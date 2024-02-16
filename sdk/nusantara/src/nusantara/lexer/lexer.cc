#include <nusantara/lexer/lexer.h>
#include <nusantara/lexer/token.h>
#include <nusantara/lexer/token_type.h>
#include <nusantara/lexer/token_type_data.h>

#include <regex>
#include <string>

#include "nstd/daftar.h"

Lexer::Lexer(std::string source, std::string content):
    source(std::move(source)), content(std::move(content)) {}

bool Lexer::match(const std::string &pattern, std::string &match) {
  std::regex regexPattern("^" + pattern);
  std::smatch matches;
  if(std::regex_search(
         this->content, matches, regexPattern,
         std::regex_constants::match_continuous
     )) {
    match = matches.str();
    this->charIndex = this->realCharIndex;
    for(const char &character : match) {
      this->realCharIndex++;
      if(character == '\n') {
        this->line++;
        this->realCharIndex = 0;
      }
    }
    this->content.replace(0, match.length(), "");
    return true;
  } else {
    return false;
  }
}

Token Lexer::getNextToken() {
  if(this->mode == LexerMode::KALIMAT) { return generateTokenKalimat(); }
  return generateTokenBawaan();
}

Token Lexer::generateTokenTidakDiKenal() {
  this->mode = LexerMode::BAWAAN;
  std::string match;
  match = content[0];
  std::string patternMatch = match;
  if(nstd::contains({"{", "}", "(", ")", "|", "+", "*"}, patternMatch)) {
    patternMatch = "\\" + patternMatch;
  }
  this->match(patternMatch, match);
  return this->createToken(TokenType::TIDAK_DIKENALI, match);
}

Token Lexer::generateTokenBawaan() {
  std::string match;
  if(this->content.empty()) {
    return this->createToken(TokenType::AKHIR_DARI_FILE, match);
  }
  for(const TokenTypeData &tokenType : this->tokenTypesBawaan) {
    TokenType type = tokenType.getType();
    if(this->match(tokenType.getPattern(), match)) {
      if(type == TokenType::WHITESPACE ||
         type == TokenType::KOMENTAR_DOKUMENTASI ||
         type == TokenType::KOMENTAR_SATU_BARIS ||
         type == TokenType::KOMENTAR_BANYAK_BARIS) {
        return getNextToken();
      }
      if(type == TokenType::KUTIP_DUA || type == TokenType::KUTIP_SATU) {
        this->mode = LexerMode::KALIMAT;
        this->modeState = LexerModeState::KALIMAT_PEMBUKA;
      }
      if(this->modeState == LexerModeState::KALIMAT_KURAWAL_BUKA) {
        if(type == TokenType::KURUNG_KURAWAL_TUTUP) {
          this->mode = LexerMode::KALIMAT;
          this->modeState = LexerModeState::KALIMAT_KURAWAL_TUTUP;
        }
      }
      if(this->modeState == LexerModeState::KALIMAT_DOLAR) {
        this->mode = LexerMode::KALIMAT;
        this->modeState = LexerModeState::KALIMAT;
      }
      return this->createToken(tokenType.getType(), match);
    }
  }
  return this->generateTokenTidakDiKenal();
}

Token Lexer::generateTokenKalimat() {
  std::string match;
  for(const TokenTypeData &tokenType : this->tokenTypesKalimat) {
    TokenType type = tokenType.getType();
    if(this->match(tokenType.getPattern(), match)) {
      if(type == TokenType::KUTIP_DUA || type == TokenType::KUTIP_SATU) {
        this->mode = LexerMode::BAWAAN;
        this->modeState = LexerModeState::KALIMAT_PENUTUP;
      }
      if(type == TokenType::DOLAR) {
        this->mode = LexerMode::BAWAAN;
        this->modeState = LexerModeState::KALIMAT_DOLAR;
      }
      if(type == TokenType::KURUNG_KURAWAL_BUKA) {
        this->mode = LexerMode::BAWAAN;
        this->modeState = LexerModeState::KALIMAT_KURAWAL_BUKA;
      }
      return this->createToken(tokenType.getType(), match);
    }
  }
  return this->generateTokenTidakDiKenal();
}

Token Lexer::createToken(const TokenType &type, const std::string &value) {
  return {
      this->source,    type,
      value,           this->line,
      this->charIndex, static_cast<int>(this->charIndex + value.length() - 1)
  };
}
