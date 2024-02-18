#include <nusantara/cli/cli.h>

#include <cstddef>
#include <format>
#include <iostream>
#include <string>

#include "nstd/daftar.h"
#include "nstd/konsol.h"
#include "nusantara/config/config.h"
#include "nusantara/core/error_info.h"
#include "nusantara/interpreter/interpreter.h"
#include "nusantara/lexer/lexer.h"
#include "nusantara/parser/parser.h"
#include "nusantara/utils/utils.h"

void Cli::input(const int& argc, char* argv[]) {
  nstd::daftar<std::string> kumpulanArgument;
  if(argc > 1) {
    for(size_t index = 1; index < argc; ++index) {
      kumpulanArgument.emplace_back(argv[index]);
    }
  }
  size_t index = 0;
  nstd::daftar<std::string> perintahInfo = {"-i", "--info"};
  nstd::daftar<std::string> perintahVersi = {"-v", "--versi"};
  bool interpreter = false;
  std::string source;
  bool onlyLexerDebug = false;
  bool onlyLexerParserDebug = false;
  for(const std::string& argument : kumpulanArgument) {
    if(argument == "-ld" && interpreter && !onlyLexerParserDebug) {
      onlyLexerDebug = true;
    } else if(argument == "-pd" && interpreter && !onlyLexerDebug) {
      onlyLexerParserDebug = true;
    } else if(argument.contains('.')) {
      source = argument;
      interpreter = true;
    } else if(nstd::contains(perintahVersi, argument)) {
      showVersi();
      return;
    } else if(nstd::contains(perintahInfo, argument)) {
      showInfo();
      return;
    } else {
      interpreter = false;
      kumpulanArgument[0] = argument;
      break;
    }
    ++index;
  }
  if(interpreter) {
    std::string input = utils::readFile(source);
    ErrorInfo errorInfo(source, input);
    Lexer lexer(source, input);
    Parser parser(errorInfo, lexer);
    if(onlyLexerDebug && !onlyLexerParserDebug) {
      while(true) {
        Token token = lexer.getNextToken();
        std::cout << token.toString() << "\n";
        if(token.getType() == TokenType::AKHIR_DARI_FILE) { break; }
      }
    } else if(!onlyLexerDebug && onlyLexerParserDebug) {
      std::unique_ptr<ParserTree> tree = parser.parse();
      tree->printTree(0);
    } else {
      std::unique_ptr<ParserTree> tree = parser.parse();
      nstd::cetak(
          std::string("Untuk sementara interpreter tidak bisa digunakan.")
      );
      // Interpreter interpreter(errorInfo);
      // interpreter.visit(tree);
    }
  } else if(kumpulanArgument.empty()) {
    showInfo();
  } else {
    nstd::cetak(std::format("Perintah '{}' tidak ada.", kumpulanArgument[0]));
    showInfo();
  }
}

void Cli::showInfo() {
  nstd::cetak(
      std::string("Sebuah alat command-line untuk Nusantara development.\n")
  );
  nstd::cetak(
      std::string("Penggunaan: nusantara <perintah|nusantara-file> [argumen]\n")
  );
  nstd::cetak(std::string("Pilihan umum:"));
  nstd::cetak(
      std::string("   -v | --versi        Untuk melihat versi nusantara.")
  );
  nstd::cetak(std::string(
      "   -i | --info         Untuk melihat informasi lebih lanjut."
  ));
}

void Cli::showVersi() { nstd::cetak(std::format("{} {}", APP, VERSION)); }
