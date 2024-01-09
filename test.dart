import 'package:nusantara/nusantara_lexer/lexer.dart';
import 'package:nusantara/nusantara_lexer/token.dart';

void main() {
	try {
		List<Token> tokens = Lexer.tokenizer("test.txt");
		for(Token t in tokens) {
			print("${t.source}:${t.line}:${t.charPosition} ${t.type.name} ${t.content}");
		}
	}catch(e) {
		print(e);
	}
}
