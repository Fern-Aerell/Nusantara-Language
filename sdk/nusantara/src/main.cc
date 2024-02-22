#include <chrono>
#include <exception>
#include <format>
#include <string>

#include "cli/cli.h"
#include "nstd/konsol.h"

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
  auto duration =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
  nstd::cetak(
      std::format("Program berjalan selama: {} milidetik.", duration.count())
  );
  return 0;
}
