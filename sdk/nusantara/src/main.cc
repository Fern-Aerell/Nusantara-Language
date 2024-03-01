#include "core/print.h"
#include "config/config.h"
#include "nstd/tipe_data/bilangan.h"
#include "nstd/tipe_data/dinamis.h"

#ifdef _WIN32
  #include <windows.h>
  #include <winnls.h>
#endif

#define EMPTY_PARAMETER ()
#define ARG_PARAMETER (int argc, char* argv[])
#define MAIN(parameter, code) \
  int main parameter { code return 0; }

//#define TEST_CODE

#ifdef TEST_CODE

MAIN(
    EMPTY_PARAMETER, PRINT("Test Code"); try {
    } catch(const std::exception& error) { PRINT(error.what()); }
)

#else

  #include <chrono>
  #include <exception>

  #include "cli/cli.h"

MAIN(
    ARG_PARAMETER, auto start = std::chrono::steady_clock::now();
  #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
  #endif
    try {
      Cli cli;
      cli.input(argc, argv);
    } catch(const std::exception& error) {
      PRINT(error.what());
    } auto end = std::chrono::steady_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    PRINTF("Program berjalan selama: {} milidetik.", duration.count());
)

#endif
