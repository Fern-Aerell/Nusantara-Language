import 'package:nusantara/nusantara_lexer/token_type.dart';

class Token {
	final String source;
	final int line;
	final int charPosition;
	final TokenType type;
	final String content;
	Token(this.source, this.line, this.charPosition, this.type, this.content);
}
