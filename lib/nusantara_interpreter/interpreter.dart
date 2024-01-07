import 'package:antlr4/antlr4.dart';
import 'package:nusantara/nusantara_antlr4/NusantaraLanguageLexer.dart';
import 'package:nusantara/nusantara_antlr4/NusantaraLanguageParser.dart';
import 'package:nusantara/nusantara_interpreter/interpreter_variable_manager.dart';

class Interpreter {

	final InterpreterVariableManager variableManager = InterpreterVariableManager();
  final CharStream input;

  Interpreter(this.input) {
		print("Catatan : Nusantara interpreter masih dalam pengembangan.");
    NusantaraLanguageLexer lexer = NusantaraLanguageLexer(input);
    TokenStream tokens = CommonTokenStream(lexer);
    NusantaraLanguageParser parser = NusantaraLanguageParser(tokens);
		parser.nusantara();
  }

}
