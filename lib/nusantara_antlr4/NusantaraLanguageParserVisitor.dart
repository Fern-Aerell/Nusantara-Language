// Generated from C:/Aerell/AerellDev/Programing Language Project/Nusantara-Language/grammar/NusantaraLanguageParser.g4 by ANTLR 4.13.1
// ignore_for_file: unused_import, unused_local_variable, prefer_single_quotes
import 'package:antlr4/antlr4.dart';

import 'NusantaraLanguageParser.dart';

/// This abstract class defines a complete generic visitor for a parse tree
/// produced by [NusantaraLanguageParser].
///
/// [T] is the eturn type of the visit operation. Use `void` for
/// operations with no return type.
abstract class NusantaraLanguageParserVisitor<T> extends ParseTreeVisitor<T> {
  /// Visit a parse tree produced by [NusantaraLanguageParser.nusantara].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitNusantara(NusantaraContext ctx);

  /// Visit a parse tree produced by the {@code pernyataanBuatDanNgisiVariable}
  /// labeled alternative in {@link NusantaraLanguageParser#pernyataan}.
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitPernyataanBuatDanNgisiVariable(PernyataanBuatDanNgisiVariableContext ctx);

  /// Visit a parse tree produced by the {@code buatDanNgisiVariableBilanganBulat}
  /// labeled alternative in {@link NusantaraLanguageParser#buat_dan_ngisi_variable}.
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitBuatDanNgisiVariableBilanganBulat(BuatDanNgisiVariableBilanganBulatContext ctx);

  /// Visit a parse tree produced by the {@code buatDanNgisiVariableBilanganDesimal}
  /// labeled alternative in {@link NusantaraLanguageParser#buat_dan_ngisi_variable}.
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitBuatDanNgisiVariableBilanganDesimal(BuatDanNgisiVariableBilanganDesimalContext ctx);

  /// Visit a parse tree produced by the {@code buatDanNgisiVariableKarakter}
  /// labeled alternative in {@link NusantaraLanguageParser#buat_dan_ngisi_variable}.
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitBuatDanNgisiVariableKarakter(BuatDanNgisiVariableKarakterContext ctx);

  /// Visit a parse tree produced by the {@code buatDanNgisiVariableKalimat}
  /// labeled alternative in {@link NusantaraLanguageParser#buat_dan_ngisi_variable}.
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitBuatDanNgisiVariableKalimat(BuatDanNgisiVariableKalimatContext ctx);

  /// Visit a parse tree produced by the {@code buatDanNgisiVariableBoolean}
  /// labeled alternative in {@link NusantaraLanguageParser#buat_dan_ngisi_variable}.
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitBuatDanNgisiVariableBoolean(BuatDanNgisiVariableBooleanContext ctx);
}