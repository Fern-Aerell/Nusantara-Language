// Generated from /home/aerell/nusantara/grammar/NusantaraLanguageParser.g4 by ANTLR 4.13.1
// ignore_for_file: unused_import, unused_local_variable, prefer_single_quotes
import 'package:antlr4/antlr4.dart';

import 'NusantaraLanguageParser.dart';

/// This abstract class defines a complete generic visitor for a parse tree
/// produced by [NusantaraLanguageParser].
///
/// [T] is the eturn type of the visit operation. Use `void` for
/// operations with no return type.
abstract class NusantaraLanguageParserVisitor<T> extends ParseTreeVisitor<T> {
  /// Visit a parse tree produced by [NusantaraLanguageParser.awal].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitAwal(AwalContext ctx);
}