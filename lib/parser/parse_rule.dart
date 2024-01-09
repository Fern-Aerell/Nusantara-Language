import 'package:nusantara/lexer/token.dart';
import 'package:nusantara/lexer/token_type_data.dart';

class ParseRule<T> {
  final String name;
  final List<T>? children;
  ParseRule({required this.name, this.children});
}