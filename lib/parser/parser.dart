import 'package:nusantara/lexer/token.dart';
import 'package:nusantara/lexer/token_type_data.dart';
import 'package:nusantara/parser/parse_rule.dart';

class Parser {
  late final List<Token> tokens;
  final List<ParseRule> rules;
  int currentTokenIndex = 0;

  Parser({required this.rules});

  bool nextToken() {
    if(currentTokenIndex < tokens.length - 1) {
      print("next");
      currentTokenIndex++;
      return true;
    }
    return false;
  }

  Token getCurrentToken() {
    return tokens[currentTokenIndex];
  }

  void parse(List<Token> tokens) {
    this.tokens = tokens;
    _walk(rules);
  }

  void _walk(List<dynamic> rules) {
    for(ParseRule rule in rules) {
      print("Rule : ${rule.name}");
      if(rule.children != null) {
        if(rule.children.runtimeType == List<TokenTypeData>) {
          List<TokenTypeData> datas = (rule.children as List<TokenTypeData>);
          int testKe = 0;
          int nilaiTest = 1;
          int nilaiMax = datas.length;
          for(TokenTypeData data in datas) {
            nextToken();
            testKe++;
            bool check = data.enumTokenType == getCurrentToken().type;
            print("Test $testKe, hasil dari ${data.enumTokenType} == ${getCurrentToken().type} : $check");
            if(check) {
              nilaiTest++;
            }
          }
        }else{
          _walk(rule.children!);
        }
      }
    }
  }
}