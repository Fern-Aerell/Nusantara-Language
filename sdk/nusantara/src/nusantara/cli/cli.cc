#include <nusantara/cli/cli.h>

#include <cstddef>
#include <format>

#include "nusantara/config/config.h"
#include "nusantara/core/core.h"
#include "nusantara/core/error_info.h"
#include "nusantara/core/konsol.h"
#include "nusantara/interpreter/interpreter.h"
#include "nusantara/lexer/lexer.h"
#include "nusantara/parser/parser.h"
#include "nusantara/utils/utils.h"

void Cli::input(nstd::konst<nstd::bulat>& argc, nstd::karakter* argv[]) {
  nstd::daftar<nstd::kalimat> kumpulanArgument;
  if (argc > 1) {
    for (size_t index = 1; index < argc; ++index) {
      kumpulanArgument.emplace_back(argv[index]);
    }
  }
  size_t index = 0;
  nstd::daftar<nstd::kalimat> perintahInfo = {"-i", "--info"};
  nstd::daftar<nstd::kalimat> perintahVersi = {"-v", "--versi"};
  nstd::benarsalah interpreter = salah;
  nstd::kalimat source;
  nstd::benarsalah onlyLexerDebug = salah;
  nstd::benarsalah onlyLexerParserDebug = salah;
  for (nstd::konst<nstd::kalimat>& argument : kumpulanArgument) {
    if (argument == "-ld" && interpreter && !onlyLexerParserDebug) {
      onlyLexerDebug = benar;
    } else if (argument == "-pd" && interpreter && !onlyLexerDebug) {
      onlyLexerParserDebug = benar;
    } else if (argument.contains('.')) {
      source = argument;
      interpreter = benar;
    } else if (nstd::contains(perintahVersi, argument)) {
      showVersi();
      return;
    } else if (nstd::contains(perintahInfo, argument)) {
      showInfo();
      return;
    } else {
      interpreter = salah;
      kumpulanArgument[0] = argument;
      break;
    }
    ++index;
  }
  if (interpreter) {
    nstd::kalimat input = utils::readFile(source);
    ErrorInfo errorInfo(source, input);
    Lexer lexer(source, input);
    Parser parser(errorInfo, lexer);
    if (onlyLexerDebug && !onlyLexerParserDebug) {
      while (true) {
        Token token = lexer.getNextToken();
        std::cout << token.toString() << "\n";
        if (token.getType() == TokenType::AKHIR_DARI_FILE) {
          break;
        }
      }
    } else if (!onlyLexerDebug && onlyLexerParserDebug) {
      std::unique_ptr<ParserTree> tree = parser.parse();
      tree->printTree(0);
    } else {
      std::unique_ptr<ParserTree> tree = parser.parse();
      Interpreter interpreter(errorInfo);
      interpreter.visit(tree);
    }
  } else if (kumpulanArgument.empty()) {
    showInfo();
  } else {
    nstd::Konsol::cetak(
        std::format("Perintah '{}' tidak ada.", kumpulanArgument[0]));
    showInfo();
  }
}

void Cli::showInfo() {
  nstd::Konsol::cetak(
      nstd::kalimat("Sebuah alat command-line untuk Nusantara development.\n"));
  nstd::Konsol::cetak(nstd::kalimat(
      "Penggunaan: nusantara <perintah|nusantara-file> [argumen]\n"));
  nstd::Konsol::cetak(nstd::kalimat("Pilihan umum:"));
  nstd::Konsol::cetak(
      nstd::kalimat("   -v | --versi        Untuk melihat versi nusantara."));
  nstd::Konsol::cetak(nstd::kalimat(
      "   -i | --info         Untuk melihat informasi lebih lanjut."));
}

void Cli::showVersi() {
  nstd::Konsol::cetak(std::format("{} {}", APP, VERSION));
}
