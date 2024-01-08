import 'package:antlr4/antlr4.dart';
import 'package:nusantara/nusantara_antlr4/NusantaraLanguageLexer.dart';
import 'package:nusantara/nusantara_antlr4/NusantaraLanguageParser.dart';

class Interpreter {

  final CharStream input;

  Interpreter(this.input) {
		print("Catatan : Nusantara interpreter masih dalam pengembangan.");
    NusantaraLanguageLexer lexer = NusantaraLanguageLexer(input);
    TokenStream tokens = CommonTokenStream(lexer);
    NusantaraLanguageParser parser = NusantaraLanguageParser(tokens);
    parser.removeErrorListeners();
    parser.nusantara();
  }



}
