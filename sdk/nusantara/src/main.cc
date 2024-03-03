#include "core/print.h"
#include "core/string.h"
#include "utils/utils.h"

#define EMPTY_PARAMETER ()
#define ARG_PARAMETER (int argc, char* argv[])
#define MAIN(parameter, code) \
  int main parameter { code return 0; }

//#define TEST_CODE

#ifdef TEST_CODE

MAIN(
    EMPTY_PARAMETER, 
    PRINT("Test Code");
    try {
			STR content = utils::readFile("examples/tes.nl");
			STR a;
			STR b = "";
			PRINT(a.empty());
			PRINT(b.empty());
			PRINT(content.empty());
    } catch(const std::exception& error) { PRINT(error.what()); }
)

#else

#include <exception>
#include "cli/cli.h"

#ifdef _WIN32
#include <windows.h>
#include <winnls.h>
#endif


MAIN(
    ARG_PARAMETER,
 		#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
	  #endif
    try {
      Cli cli;
      cli.input(argc, argv);
    } catch(const std::exception& error) {
      PRINT(error.what());
    }
)

#endif
