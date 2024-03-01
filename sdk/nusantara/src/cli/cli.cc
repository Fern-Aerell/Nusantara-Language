#include "cli/cli.h"

#include <iostream>
#include <string>
#include <vector>

#include <format>
#include "config/config.h"
#include "error/error_info.h"
#include "interpreter/interpreter.h"
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "utils/utils.h"

void Cli::input(const int& argc, char* argv[]) {
  std::vector<std::string> kumpulanArgument;
  if(argc > 1) {
    for(size_t index = 1; index < argc; ++index) {
      kumpulanArgument.emplace_back(argv[index]);
    }
  }
  size_t index = 0;
  std::vector<std::string> perintahInfo = {"-i", "--info"};
  std::vector<std::string> perintahVersi = {"-v", "--versi"};
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
    } else if(utils::contains(perintahVersi, argument)) {
      showVersi();
      return;
    } else if(utils::contains(perintahInfo, argument)) {
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
  std::cout << "Sebuah alat command-line untuk Nusantara development.\n"
            << "\n";
  std::cout << "Penggunaan: nusantara <perintah|nusantara-file> [argumen]\n"
            << "\n";
  std::cout << "Pilihan umum:"
            << "\n";
  std::cout << "   -v | --versi        Untuk melihat versi nusantara."
            << "\n";
  std::cout << "   -i | --info         Untuk melihat informasi lebih lanjut."
            << "\n";
}

void Cli::showVersi() { std::cout << std::format("{} {}", APP, VERSION); }
