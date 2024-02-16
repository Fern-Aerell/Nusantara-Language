#include <nusantara/core/error_info.h>
#include <nusantara/lexer/lexer.h>
#include <nusantara/parser/parser.h>
#include <nusantara/utils/utils.h>

#include <exception>
#include <iostream>

#include "nusantara/cli/cli.h"

int main(int argc, char* argv[]) {
  try {
    Cli cli;
    cli.input(argc, argv);
  } catch(const std::exception& error) { std::cout << error.what() << "\n"; }
  return 0;
}
