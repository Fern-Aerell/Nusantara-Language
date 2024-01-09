import 'package:nusantara/cli/cli.dart';
import 'package:nusantara/cli/features/argument_empty_callback.dart';
import 'package:nusantara/cli/features/argument_invalid_callback.dart';
import 'package:nusantara/cli/features/cli_feature.dart';
import 'package:nusantara/cli/features/input_file.dart';
import 'package:nusantara/cli/features/opsi_global.dart';
import 'package:nusantara/cli/features/opsi_globals.dart';
import 'package:nusantara/interpreter/interpreter.dart';
import 'package:nusantara/lexer/lexer.dart';
import 'package:nusantara/lexer/token.dart';
import 'package:nusantara/lexer/token_type_data.dart';
import 'package:nusantara/parser/parse_rule.dart';
import 'package:nusantara/parser/parser.dart';

import 'config/config.dart';
import 'token/tokens.dart';

List<ParseRule> parseRule = [
  ParseRule(
      name: "nusantara",
      children: [
        ParseRule<TokenTypeData>(
            name: "bikin variable bilangan bulat",
            children: [
              enumToTokenTypeData(TokenType.TIPE_DATA_BILANGAN_BULAT),
              enumToTokenTypeData(TokenType.IDENTIFIKASI),
              enumToTokenTypeData(TokenType.SAMA_DENGAN),
              enumToTokenTypeData(TokenType.NILAI_BILANGAN_BULAT),
              enumToTokenTypeData(TokenType.TITIK_KOMA),
            ]
        )
      ]
  )
];

void main(List<String> arguments) {
  try {
    // Cli feature
    List<CliFeature> features = [
      InputFile(nusantaraLanguageFileExtension, (file) {
        Interpreter();
        Lexer lexer = Lexer(tokenTypeData: tokenTypeData);
        List<Token> tokens = lexer.tokenizerFromPath(file.path);
        // Debug tokens
        // for(Token token in tokens) {
        //   print(token);
        // }
        Parser parser = Parser(rules: parseRule);
        parser.parse(tokens);
      }),
      OpsiGlobals(
          [
            OpsiGlobal("versi", "v", "Untuk melihat versi nusantara.", (_) {
              print("$appName $appVersion");
            }),
            OpsiGlobal("info", "i", "Untuk melihat informasi lebih lanjut.", (list) {
              print("Sebuah alat command-line untuk Nusantara development.");
              print("");
              print("Penggunaan : nusantara <perintah|nlfile> [argumen]");
              print("");
              if(list.isNotEmpty) {
                for(OpsiGlobal opsiGlobal in list) {
                  String name = "--${opsiGlobal.name}";
                  String alias = "-${opsiGlobal.alias}";
                  String info = opsiGlobal.info;
                  print(" $alias | $name    $info");
                }
                print("");
              }
            })
          ]
      ),
      ArgumentEmptyCallback((arguments, features) {
        List<OpsiGlobal> opsiGlobal = (features.firstWhere((element) => element.runtimeType == OpsiGlobals) as OpsiGlobals).list;
        opsiGlobal.firstWhere((element) => element.name == "info").callback(opsiGlobal);
      },),
      ArgumentInvalidCallback((argument, features) {
        print("Perintah \"$argument\" tidak ada.");
        (features.firstWhere((element) => element.runtimeType == ArgumentEmptyCallback)).execute();
      },)
    ];
    // Intialize cli
    Cli cli = Cli(arguments, features);
    // Eksekusi perintah cli
    cli.execute();
  }catch(error) {
    print(error);
  }
}
