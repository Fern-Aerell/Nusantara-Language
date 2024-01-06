import 'dart:io';

import 'package:antlr4/antlr4.dart';
import 'package:nusantara/nusantara_antlr4/NusantaraLanguageLexer.dart';
import 'package:nusantara/nusantara_antlr4/NusantaraLanguageParser.dart';

class Intepreter {

  final File file;
  late final CharStream _charStream;

  Intepreter(this.file) {
    _intepreter();
  }

  void _intepreter() async {
    _charStream = await InputStream.fromPath(file.path);
    NusantaraLanguageLexer lexer = NusantaraLanguageLexer(_charStream);
    TokenStream tokens = CommonTokenStream(lexer);
    NusantaraLanguageParser parser = NusantaraLanguageParser(tokens);
    parser.nusantara();
  }

}