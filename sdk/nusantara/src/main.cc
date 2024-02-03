#include "error_info.h"
#include "lexer.h"
#include "parser.h"
#include <exception>
#include <iostream>
#include <string>
#include <utils.h>

int main(int argc, char *argv[])
{
  try {
    std::string source = "examples/halo_dunia.nl";
    std::string input = utils::readFile(source);
    ErrorInfo errorInfo(source, input);
    Lexer lexer(source, input);
    // while (true) {
    //   Token token = lexer.getNextToken();
    //   std::cout << token.toString() << "\n";
    //   if(token.getType() == TokenType::AKHIR_DARI_FILE) {break;}
    // }
    Parser parser(errorInfo, lexer);
    std::unique_ptr<ParserTree> tree = parser.parse();
    tree->printTree(0);
  } catch (const std::exception& error) {
    std::cout << error.what() << "\n";
  }
  return 0;
}
