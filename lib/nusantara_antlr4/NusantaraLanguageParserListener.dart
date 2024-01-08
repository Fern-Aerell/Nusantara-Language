// Generated from C:/Aerell/AerellDev/Programing Language Project/Nusantara-Language/grammar/NusantaraLanguageParser.g4 by ANTLR 4.13.1
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

  /// Enter a parse tree produced by the [pernyataanBuatDanNgisiVariable]
  /// labeled alternative in [file.parserName>.pernyataan].
  /// [ctx] the parse tree
  void enterPernyataanBuatDanNgisiVariable(PernyataanBuatDanNgisiVariableContext ctx);
  /// Exit a parse tree produced by the [pernyataanBuatDanNgisiVariable]
  /// labeled alternative in [NusantaraLanguageParser.pernyataan].
  /// [ctx] the parse tree
  void exitPernyataanBuatDanNgisiVariable(PernyataanBuatDanNgisiVariableContext ctx);

  /// Enter a parse tree produced by the [buatDanNgisiVariableBilanganBulat]
  /// labeled alternative in [file.parserName>.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void enterBuatDanNgisiVariableBilanganBulat(BuatDanNgisiVariableBilanganBulatContext ctx);
  /// Exit a parse tree produced by the [buatDanNgisiVariableBilanganBulat]
  /// labeled alternative in [NusantaraLanguageParser.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void exitBuatDanNgisiVariableBilanganBulat(BuatDanNgisiVariableBilanganBulatContext ctx);

  /// Enter a parse tree produced by the [buatDanNgisiVariableBilanganDesimal]
  /// labeled alternative in [file.parserName>.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void enterBuatDanNgisiVariableBilanganDesimal(BuatDanNgisiVariableBilanganDesimalContext ctx);
  /// Exit a parse tree produced by the [buatDanNgisiVariableBilanganDesimal]
  /// labeled alternative in [NusantaraLanguageParser.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void exitBuatDanNgisiVariableBilanganDesimal(BuatDanNgisiVariableBilanganDesimalContext ctx);

  /// Enter a parse tree produced by the [buatDanNgisiVariableKarakter]
  /// labeled alternative in [file.parserName>.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void enterBuatDanNgisiVariableKarakter(BuatDanNgisiVariableKarakterContext ctx);
  /// Exit a parse tree produced by the [buatDanNgisiVariableKarakter]
  /// labeled alternative in [NusantaraLanguageParser.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void exitBuatDanNgisiVariableKarakter(BuatDanNgisiVariableKarakterContext ctx);

  /// Enter a parse tree produced by the [buatDanNgisiVariableKalimat]
  /// labeled alternative in [file.parserName>.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void enterBuatDanNgisiVariableKalimat(BuatDanNgisiVariableKalimatContext ctx);
  /// Exit a parse tree produced by the [buatDanNgisiVariableKalimat]
  /// labeled alternative in [NusantaraLanguageParser.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void exitBuatDanNgisiVariableKalimat(BuatDanNgisiVariableKalimatContext ctx);

  /// Enter a parse tree produced by the [buatDanNgisiVariableBoolean]
  /// labeled alternative in [file.parserName>.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void enterBuatDanNgisiVariableBoolean(BuatDanNgisiVariableBooleanContext ctx);
  /// Exit a parse tree produced by the [buatDanNgisiVariableBoolean]
  /// labeled alternative in [NusantaraLanguageParser.buat_dan_ngisi_variable].
  /// [ctx] the parse tree
  void exitBuatDanNgisiVariableBoolean(BuatDanNgisiVariableBooleanContext ctx);
}