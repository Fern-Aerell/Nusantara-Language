#include "cli/cli.h"

#include <iostream>
#include <vector>

#include <format>
#include "config/config.h"
#include "core/core.h"
#include "core/string.h"
#include "error/error_info.h"
#include "interpreter/interpreter.h"
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "utils/utils.h"
#include "core/print.h"

void Cli::input(const int& argc, char* argv[]) {
  std::vector<STR> kumpulanArgument;
  if(argc > 1) {
    for(size_t index = 1; index < argc; ++index) {
      kumpulanArgument.emplace_back(argv[index]);
    }
  }
  size_t index = 0;
  std::vector<STR> perintahInfo = {"-i", "--info"};
  std::vector<STR> perintahVersi = {"-v", "--versi"};
  bool interpreter = false;
  STR source;
  bool onlyLexerDebug = false;
  bool onlyLexerParserDebug = false;
  for(const STR& argument : kumpulanArgument) {
    if(argument == "-ld" && interpreter && !onlyLexerParserDebug) {
      onlyLexerDebug = true;
    } else if(argument == "-pd" && interpreter && !onlyLexerDebug) {
      onlyLexerParserDebug = true;
    } else if(argument.contains('.')) {
      source = argument;
      interpreter = true;
    } else if(utils::contains(perintahVersi, argument) && index == 0) {
      showVersi();
      return;
    } else if(utils::contains(perintahInfo, argument) && index == 0) {
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
    STR input = utils::readFile(source);
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
      Interpreter interpreter(errorInfo);
      interpreter.visit(tree);
    }
  } else if(kumpulanArgument.empty()) {
    showInfo();
  } else {
    std::cout << std::format("Perintah '{}' tidak ada.", kumpulanArgument[0])
              << "\n";
    showInfo();
  }
}

void Cli::showInfo() {
  PRINT("Sebuah alat command-line untuk Nusantara development.\n");
  PRINT("Penggunaan: nusantara <perintah|nusantara-file> [argumen]\n");
  PRINT("Pilihan umum:");
  PRINT("   -v | --versi        Untuk melihat versi nusantara.");
  PRINT("   -i | --info         Untuk melihat informasi lebih lanjut.");
}

void Cli::showVersi() { PRINT(STD format("{} {}", APP, VERSION)); }
