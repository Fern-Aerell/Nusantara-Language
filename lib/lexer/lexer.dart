import 'dart:io';

import 'token_type_data.dart';
import 'token.dart';

class Lexer {

  late final List<TokenTypeData> tokenTypeData;

  Lexer({required this.tokenTypeData}) {
    for(TokenTypeData type in tokenTypeData) {
      if(tokenTypeData.where((element) => element.enumTokenType == type.enumTokenType).length > 1) {
        throw "Terdapat 2 atau lebih tipe token dengan nama yang sama : ${type.enumTokenType}";
      }
    }
  }

  Lexer.fromJson(List data, Enum Function(String name) stringToEnum) {
    tokenTypeData = [];
    for(Map<String, dynamic> tokenType in data) {
      tokenTypeData.add(TokenTypeData.fromJson(tokenType, stringToEnum));
    }
  }

  List<Token> tokenizerFromPath(String path) {
    File file = File(path);
    if(!file.existsSync()) throw "File '$path' tidak ada";
    return tokenizerFromString(file.readAsStringSync(), source: file.path);
  }

  List<Token> tokenizerFromString(String content, {String source = "unknown"}) {
    List<Token> tokens = [];
    int line  = 1;
    int charPosition = 1;
    _tokenizer(source, tokens, line, content, charPosition);
    return tokens;
  }

  void _tokenizer(String source, List<Token> tokens, int line, String content, int charPosition) {
    // Unknown Token
    bool isUnknown = true;
    // isNewline
    Match? newLine = RegExp("\n").matchAsPrefix(content);
    if(newLine != null) {
      line++;
      charPosition = 0;
    }
    // Token
    for(TokenTypeData tokenType in tokenTypeData) {
      Match? match = tokenType.rule.matchAsPrefix(content);
      if(match != null) {
        isUnknown = false;
        int startPositionInLine = match.start;
        int endPositionInLine = match.end;
        String value = content.substring(startPositionInLine, endPositionInLine);
        if(!tokenType.skip) {
          tokens.add(Token(source: source, line: line, startPositionInLine: startPositionInLine + charPosition, endPositionInLine: endPositionInLine, type: tokenType.enumTokenType, content: value));
        }
        charPosition += value.length;
        content = content.substring(endPositionInLine, content.length);
        if(content.isNotEmpty) {
          _tokenizer(source, tokens, line, content, charPosition);
        }
        break;
      }else{
        continue;
      }
    }
    if(isUnknown) {
      throw "Token tidak di kenali $source:$line:$charPosition -> ${content.split("\n")[0]}";
    }
  }

  List<Map<String, dynamic>> toJson() {
    List<Map<String, dynamic>> data = [];
    for(TokenTypeData type in tokenTypeData) {
      data.add(type.toJson());
    }
    return data;
  }

}