import 'dart:io';

import 'package:nusantara/nusantara_lexer/token.dart';
import 'package:nusantara/nusantara_lexer/token_type.dart';

class Lexer {
	static List<Token> tokenizer(String path) {
		List<Token>	tokens = [];
		File file = File(path);
		String source = file.path;
		String sourceContent = file.readAsStringSync();
		if(!file.existsSync()) throw "File '$source' tidak di temukan";
		List<String> chars = sourceContent.split("");
		String content = "";
		int line = 1;
		int realCharPosition = 1;
		int charPosition = 1;
		int charPositionFreeze = 0;
		bool isNum = false;
		bool isQuote = false;
		bool isDQuote = false;
		bool isLetter = false;
		for(String char in chars) {
			// Number
			if(Lexer.isNumber(char) && !isQuote) {
				content += char;
				isNum = true;
			}else if(Lexer.isComa(char) && isNum) {
				if(content.contains(",")) kesalahan(source, sourceContent, line, charPosition, "Ada 2 koma ',' pada bilangan desimal");
				content += char;
			}else if(content.isNotEmpty && isNum) {
				if(content.contains(",")) { 
					if(content.endsWith(",")) kesalahan(source, sourceContent, line, charPosition, "Bilangan desimal ini kurang lengkap"); 
					tokens.add(Token(source, line, charPosition, TokenType.bilanganDesimal, content));
				}else{
					tokens.add(Token(source, line, charPosition, TokenType.bilanganBulat, content));
				}
				content = "";
				isNum = false;
			}
			// Quote
			if(Lexer.isQuote(char) && !isDQuote) {
				content += char;
				if(isQuote) {
					if(content.endsWith("'") && content.endsWith("'")) {
						isQuote = false;
					}else{
						kesalahan(source, sourceContent, line, charPosition, "Kutip satu harus di tutup dengan kutip satu");
					}
					if(content.length == 3) {
						tokens.add(Token(source, line, charPosition, TokenType.karakter, content));
					}else{
						tokens.add(Token(source, line, charPosition, TokenType.kalimat, content));
					}
					content = "";
				}else{
					isQuote = true;
				}
			}else if(isQuote) {
				content += char;
				if(!sourceContent.substring(realCharPosition, sourceContent.length).contains("'")) { 
					kesalahan(source, sourceContent, line, charPosition, "kalimat atau karakter ini tidak memiliki akhir");
				}
			}
			// DQuote
			if(Lexer.isDQuote(char) && !isQuote) {
				content += char;
				if(isDQuote) {
					if(content.endsWith("\"") && content.endsWith("\"")) {
						isDQuote = false;
					}else{
						kesalahan(source, sourceContent, line, charPosition, "Kutip dua harus di tutup dengan kutip dua");
					}
					if(content.length == 3) {
						tokens.add(Token(source, line, charPosition, TokenType.karakter, content));
					}else{
						tokens.add(Token(source, line, charPosition, TokenType.kalimat, content));
					}
					content = "";
				}else{
					isDQuote = true;
				}
			}else if(isDQuote) {
				content += char;
				if(!sourceContent.substring(realCharPosition, sourceContent.length).contains("\"")) { 
					kesalahan(source, sourceContent, line, charPosition, "kalimat atau karakter ini tidak memiliki akhir");
				}
			}
			// Letter
			if((Lexer.isLetter(char) || Lexer.regMatch("_", char)) && !isDQuote && !isQuote && !isNum) {
				content += char;
				isLetter = true;
			}else if(Lexer.isNumber(char) && isLetter){
				content += char;
			}else{
				isLetter = false;
				tokens.add(Token(source, line, charPosition, TokenType.identifikasi, content));
				content = "";
			}
			// New Line
			if(Lexer.isNewLine(char) && !isQuote && !isDQuote) {
				line++;
				charPosition = 0;
				content = "";
				isNum = false;
			}
			// Char Position
			if(!isNum && !isQuote && !isDQuote && !isLetter) {
				if(charPositionFreeze > 0) {
					charPosition += charPositionFreeze;
					charPosition++;
					charPositionFreeze = 0;
				}else{
					charPosition++;
				}
			}else{
				if(charPositionFreeze < 1) charPositionFreeze = 1;
				charPositionFreeze++;
			}
			realCharPosition++;
		}
		return tokens;
	}
	static bool regMatch(String pattern, String input) {
		return RegExp(pattern).hasMatch(input);
	}
	static bool isTab(String input) {
		return regMatch("\t", input);
	}
	static bool isSpace(String input) {
		return regMatch(" ", input);
	}
	static bool isNewLine(String input) {
		return regMatch("\n", input);
	}
	static bool isNumber(String input) {
		return regMatch("[0-9]", input);
	}
	static bool isLetter(String input) {
		return regMatch("[a-zA-Z]", input);
	}
	static bool isQuote(String input) {
		return regMatch("'", input);
	}
	static bool isDQuote(String input) {
		return regMatch("\"", input);
	}
	static bool isComa(String input) {
		return regMatch(",", input);
	}
}

void kesalahan(String source, String sourceContent, int line, int charPosition, String message) {
	List<String> sourceContentList = sourceContent.split("\n");
	String prefix = "Ada kesalahan pada $source:$line:${charPosition}\n\n";
	String lineErrorPrefix = "$line| ";
	String lineError = "$lineErrorPrefix${sourceContentList[line - 1]}\n";
	String arrow = "^\n".padLeft(charPosition + lineErrorPrefix.length + 1, " ");
	String info = message.padLeft(arrow.length + (message.length ~/ 2), " ");
	throw "$prefix$lineError$arrow$info";
}
