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

  /// Visit a parse tree produced by [NusantaraLanguageParser.pernyataan].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitPernyataan(PernyataanContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.muat_file].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitMuat_file(Muat_fileContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.blok_kode].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitBlok_kode(Blok_kodeContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.parameter_fungsi_kosong].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitParameter_fungsi_kosong(Parameter_fungsi_kosongContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.parameter_buat_fungsi].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitParameter_buat_fungsi(Parameter_buat_fungsiContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.buat_fungsi].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitBuat_fungsi(Buat_fungsiContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.parameter_panggil_fungsi].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitParameter_panggil_fungsi(Parameter_panggil_fungsiContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.panggil_fungsi].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitPanggil_fungsi(Panggil_fungsiContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.tipe_data_variable].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitTipe_data_variable(Tipe_data_variableContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.buat_variable].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitBuat_variable(Buat_variableContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.nilai_variable].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitNilai_variable(Nilai_variableContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.ngisi_variable].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitNgisi_variable(Ngisi_variableContext ctx);

  /// Visit a parse tree produced by [NusantaraLanguageParser.buat_dan_ngisi_variable].
  /// [ctx] the parse tree.
  /// Return the visitor result.
  T? visitBuat_dan_ngisi_variable(Buat_dan_ngisi_variableContext ctx);
}