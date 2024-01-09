import 'dart:convert';
import 'dart:io';

void main() {
  File inputFile = File("grammar/tokens.json");
  File outputFile = File("bin/token/tokens.dart");
  JsonDecoder jsonDecoder = JsonDecoder();
  List datas = jsonDecoder.convert(inputFile.readAsStringSync());

  String content = "// this file is generated with a generator\n\n";
  content += "import 'package:nusantara/lexer/token_type_data.dart';\n\n";

  // Generate Enum TokenType
  content += "enum TokenType {\n";
  for(int i = 0; i < datas.length; i++) {
    content += "  ${datas[i]["name"]}";
    if(i < datas.length - 1) {
      content += ",\n";
    }else{
      content += ";\n";
    }
  }

  // Generate TokenTypeData List
  content += "  @override\n  String toString() {\n    return name;\n  }\n}\n\n";
  content += "List<TokenTypeData> tokenTypeData = [\n";
  for(int i = 0; i < datas.length; i++) {
    String name = datas[i]["name"];
    String pattern = datas[i]["rule"]["pattern"];
    bool caseSensitive = datas[i]["rule"]["case_sensitive"];
    bool dotAll = datas[i]["rule"]["dot_all"];
    bool multiline = datas[i]["rule"]["multiline"];
    bool unicode = datas[i]["rule"]["unicode"];
    bool skip = datas[i]["skip"];
    content += "  TokenTypeData(enumTokenType: TokenType.$name, rule: RegExp(\"$pattern\", multiLine: $multiline, dotAll: $dotAll, caseSensitive: $caseSensitive, unicode: $unicode), skip: $skip)";
    if(i < datas.length - 1) {
      content += ",\n";
    }else{
      content += "\n";
    }
  }
  content += "];\n\n";

  // Generate stringToTokenType
  content += "TokenType stringToTokenType(String name) {\n  switch(name) {\n";
  for(int i = 0; i < datas.length; i++) {
    String name = datas[i]["name"];
    content += '    case "$name":\n';
    content += '      return TokenType.$name;\n';
  }
  content += "    default:\n";
  content += '      throw "Tidak ada tipe token dengan nama \$name";\n  }\n}\n\n';

  // Generate enumToTokenTypeData
  content += "TokenTypeData enumToTokenTypeData(TokenType type) {\n";
  content += "  return tokenTypeData.firstWhere((element) => element.enumTokenType == type);\n";
  content += '}\n\n';

  // End Of File
  content += "// End of file.";
  outputFile.writeAsString(content);
}