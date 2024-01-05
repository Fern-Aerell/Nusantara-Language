// Generated from /home/aerell/nusantara/grammar/NusantaraLanguageParser.g4 by ANTLR 4.13.1
// ignore_for_file: unused_import, unused_local_variable, prefer_single_quotes
import 'package:antlr4/antlr4.dart';

import 'NusantaraLanguageParser.dart';
import 'NusantaraLanguageParserVisitor.dart';

/// This class provides an empty implementation of [NusantaraLanguageParserVisitor],
/// which can be extended to create a visitor which only needs to handle
/// a subset of the available methods.
///
/// [T] is the return type of the visit operation. Use `void` for
/// operations with no return type.
class NusantaraLanguageParserBaseVisitor<T> extends ParseTreeVisitor<T> implements NusantaraLanguageParserVisitor<T> {
  /// The default implementation returns the result of calling
  /// [visitChildren] on [ctx].
  @override
  T? visitAwal(AwalContext ctx) => visitChildren(ctx);
}