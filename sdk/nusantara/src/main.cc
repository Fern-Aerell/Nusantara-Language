#include "nusantara/interpreter/interpreter.h"
#include "nusantara/parser/parser_tree.h"
#include <exception>
#include <memory>
#include <string>
#include <iostream>
#include <nusantara/utils/utils.h>
#include <nusantara/core/error_info.h>
#include <nusantara/lexer/lexer.h>
#include <nusantara/parser/parser.h>

int main(int argc, char *argv[])
{
  --argc; 
  --argv;
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
    // tree->printTree(0);
    Interpreter interpreter;
    interpreter.visit(tree);
  }catch(const std::exception& error) {
    std::cout << error.what() << "\n";
  }
  return 0;
}