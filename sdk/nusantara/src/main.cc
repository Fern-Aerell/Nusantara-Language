#include <nusantara/core/error_info.h>
#include <nusantara/lexer/lexer.h>
#include <nusantara/parser/parser.h>
#include <nusantara/utils/utils.h>

#include <chrono>
#include <exception>
#include <format>
#include <string>

#include "nstd/konsol.h"
#include "nusantara/cli/cli.h"

#ifdef _WIN32
  #include <windows.h>
  #include <winnls.h>
#endif

int main(int argc, char* argv[]) {
  auto start = std::chrono::steady_clock::now();
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif
  try {
    Cli cli;
    cli.input(argc, argv);
  } catch(const std::exception& error) {
    nstd::cetak(std::string(error.what()));
  }
  auto end = std::chrono::steady_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start);
  nstd::cetak(
      std::format("Program berjalan selama: {} detik.", duration.count())
  );
  return 0;
}
