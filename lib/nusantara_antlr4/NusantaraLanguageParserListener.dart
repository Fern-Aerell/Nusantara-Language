// Generated from /home/aerell/nusantara/grammar/NusantaraLanguageParser.g4 by ANTLR 4.13.1
// ignore_for_file: unused_import, unused_local_variable, prefer_single_quotes
import 'package:antlr4/antlr4.dart';

import 'NusantaraLanguageParser.dart';

/// This abstract class defines a complete listener for a parse tree produced by
/// [NusantaraLanguageParser].
abstract class NusantaraLanguageParserListener extends ParseTreeListener {
  /// Enter a parse tree produced by [NusantaraLanguageParser.nusantara].
  /// [ctx] the parse tree
  void enterNusantara(NusantaraContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.nusantara].
  /// [ctx] the parse tree
  void exitNusantara(NusantaraContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.pernyataan].
  /// [ctx] the parse tree
  void enterPernyataan(PernyataanContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.pernyataan].
  /// [ctx] the parse tree
  void exitPernyataan(PernyataanContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.komentar].
  /// [ctx] the parse tree
  void enterKomentar(KomentarContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.komentar].
  /// [ctx] the parse tree
  void exitKomentar(KomentarContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.muat_file].
  /// [ctx] the parse tree
  void enterMuat_file(Muat_fileContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.muat_file].
  /// [ctx] the parse tree
  void exitMuat_file(Muat_fileContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.blok_kode].
  /// [ctx] the parse tree
  void enterBlok_kode(Blok_kodeContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.blok_kode].
  /// [ctx] the parse tree
  void exitBlok_kode(Blok_kodeContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.parameter_fungsi_kosong].
  /// [ctx] the parse tree
  void enterParameter_fungsi_kosong(Parameter_fungsi_kosongContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.parameter_fungsi_kosong].
  /// [ctx] the parse tree
  void exitParameter_fungsi_kosong(Parameter_fungsi_kosongContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.parameter_buat_fungsi].
  /// [ctx] the parse tree
  void enterParameter_buat_fungsi(Parameter_buat_fungsiContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.parameter_buat_fungsi].
  /// [ctx] the parse tree
  void exitParameter_buat_fungsi(Parameter_buat_fungsiContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.buat_fungsi].
  /// [ctx] the parse tree
  void enterBuat_fungsi(Buat_fungsiContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.buat_fungsi].
  /// [ctx] the parse tree
  void exitBuat_fungsi(Buat_fungsiContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.parameter_panggil_fungsi].
  /// [ctx] the parse tree
  void enterParameter_panggil_fungsi(Parameter_panggil_fungsiContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.parameter_panggil_fungsi].
  /// [ctx] the parse tree
  void exitParameter_panggil_fungsi(Parameter_panggil_fungsiContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.panggil_fungsi].
  /// [ctx] the parse tree
  void enterPanggil_fungsi(Panggil_fungsiContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.panggil_fungsi].
  /// [ctx] the parse tree
  void exitPanggil_fungsi(Panggil_fungsiContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.tipe_data_variable].
  /// [ctx] the parse tree
  void enterTipe_data_variable(Tipe_data_variableContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.tipe_data_variable].
  /// [ctx] the parse tree
  void exitTipe_data_variable(Tipe_data_variableContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.buat_variable].
  /// [ctx] the parse tree
  void enterBuat_variable(Buat_variableContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.buat_variable].
  /// [ctx] the parse tree
  void exitBuat_variable(Buat_variableContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.nilai_variable].
  /// [ctx] the parse tree
  void enterNilai_variable(Nilai_variableContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.nilai_variable].
  /// [ctx] the parse tree
  void exitNilai_variable(Nilai_variableContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.ngisi_variable].
  /// [ctx] the parse tree
  void enterNgisi_variable(Ngisi_variableContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.ngisi_variable].
  /// [ctx] the parse tree
  void exitNgisi_variable(Ngisi_variableContext ctx);

  /// Enter a parse tree produced by [NusantaraLanguageParser.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void enterBuat_dan_ngisi_variable(Buat_dan_ngisi_variableContext ctx);
  /// Exit a parse tree produced by [NusantaraLanguageParser.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void exitBuat_dan_ngisi_variable(Buat_dan_ngisi_variableContext ctx);
}