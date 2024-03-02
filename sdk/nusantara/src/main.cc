
#include "core/print.h"
#include "nstd/manager/variable_manager.h"
#include "nstd/tipe_data/identifikasi.h"
#include "nstd/tipe_data/kalimat.h"
#include "nstd/variable/variable.h"

#ifdef _WIN32
  #include <windows.h>
  #include <winnls.h>
#endif

#define EMPTY_PARAMETER ()
#define ARG_PARAMETER (int argc, char* argv[])
#define MAIN(parameter, code) \
  int main parameter { code return 0; }

#define TEST_CODE

#ifdef TEST_CODE

MAIN(
    EMPTY_PARAMETER, 
    PRINT("Test Code");
    nstd::variable_manager vars;
    vars.declare("umur");
    vars.define("umur", nstd::variable(nstd::dinamis(10)));
    nstd::identifikasi test("umur", vars);
    test = 15;
    PRINT(test);
    try {
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
