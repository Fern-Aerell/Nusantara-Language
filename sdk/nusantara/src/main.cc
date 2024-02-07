#include "nusantara/core/core.h"
#include "nusantara/lexer/token.h"
#include "nusantara/lexer/token_type.h"
#include "nusantara/parser/parser_rule.h"
#include "nusantara/parser/parser_tree.h"
#include "nusantara/visitor/visitor.h"
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
    // std::string source = "examples/halo_dunia.nl";
    // std::string input = utils::readFile(source);
    // ErrorInfo errorInfo(source, input);
    // Lexer lexer(source, input);
    // while (true) {
    //   Token token = lexer.getNextToken();
    //   std::cout << token.toString() << "\n";
    //   if(token.getType() == TokenType::AKHIR_DARI_FILE) {break;}
    // }
    // Parser parser(errorInfo, lexer);
    // std::unique_ptr<ParserTree> tree = parser.parse();
    // tree->printTree(0);
    std::unique_ptr<ParserTree> tree = std::make_unique<ParserRuleTree>(ParserRule::nilai);
    Token token("unknown", TokenType::BENAR, "benar", 0, 0);
    std::unique_ptr<ParserTree> nilai = std::make_unique<ParserTokenTree>(std::move(token));
    tree->addChild(std::move(nilai));
    TestVisitor visitor;
    nstd::dinamis value = visitor.visit(tree);
    if(!nstd::isKosong(value)) {
      std::cout << nstd::asBenarSalah(value) << "\n";
    }
  }catch(const std::exception& error) {
    std::cout << error.what() << "\n";
  }
  return 0;
}