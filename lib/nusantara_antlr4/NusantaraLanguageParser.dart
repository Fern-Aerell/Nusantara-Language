// Generated from C:/Aerell/AerellDev/Programing Language Project/Nusantara-Language/grammar/NusantaraLanguageParser.g4 by ANTLR 4.13.1
// ignore_for_file: unused_import, unused_local_variable, prefer_single_quotes
import 'package:antlr4/antlr4.dart';

import 'NusantaraLanguageParserListener.dart';
import 'NusantaraLanguageParserBaseListener.dart';
import 'NusantaraLanguageParserVisitor.dart';
import 'NusantaraLanguageParserBaseVisitor.dart';
const int RULE_nusantara = 0, RULE_pernyataan = 1, RULE_buat_dan_ngisi_variable = 2;
class NusantaraLanguageParser extends Parser {
  static final checkVersion = () => RuntimeMetaData.checkVersion('4.13.1', RuntimeMetaData.VERSION);
  static const int TOKEN_EOF = IntStream.EOF;

  static final List<DFA> _decisionToDFA = List.generate(
      _ATN.numberOfDecisions, (i) => DFA(_ATN.getDecisionState(i), i));
  static final PredictionContextCache _sharedContextCache = PredictionContextCache();
  static const int TOKEN_MUAT = 1, TOKEN_TIPE_DATA_BILANGAN_BULAT = 2, TOKEN_TIPE_DATA_BILANGAN_DESIMAL = 3, 
                   TOKEN_TIPE_DATA_KARAKTER = 4, TOKEN_TIPE_DATA_KALIMAT = 5, 
                   TOKEN_TIPE_DATA_BOOLEAN = 6, TOKEN_NILAI_BILANGAN_BULAT = 7, 
                   TOKEN_NILAI_BILANGAN_DESIMAL = 8, TOKEN_NILAI_KARAKTER = 9, 
                   TOKEN_NILAI_KALIMAT = 10, TOKEN_NILAI_BOOLEAN = 11, TOKEN_TAMBAH = 12, 
                   TOKEN_KURANG = 13, TOKEN_KALI = 14, TOKEN_BAGI = 15, 
                   TOKEN_SISA_BAGI = 16, TOKEN_KUTIP_SATU = 17, TOKEN_KUTIP_DUA = 18, 
                   TOKEN_IDENTIFIKASI = 19, TOKEN_SAMA_DENGAN = 20, TOKEN_TITIK_KOMA = 21, 
                   TOKEN_KURUNG_BUKA = 22, TOKEN_KURUNG_TUTUP = 23, TOKEN_KURUNG_KURAWAL_BUKA = 24, 
                   TOKEN_KURUNG_KURAWAL_TUTUP = 25, TOKEN_KURUNG_SIKU_BUKA = 26, 
                   TOKEN_KURUNG_SIKU_TUTUP = 27, TOKEN_KURANG_DARI = 28, 
                   TOKEN_LEBIH_BESAR_DARI = 29, TOKEN_KURANG_DARI_SAMA_DENGAN = 30, 
                   TOKEN_LEBIH_BESAR_DARI_SAMA_DENGAN = 31, TOKEN_TANDA_TANYA = 32, 
                   TOKEN_TANDA_SERU = 33, TOKEN_KOMA = 34, TOKEN_TITIK = 35, 
                   TOKEN_DOLAR = 36, TOKEN_KOMENTAR_SATU_BARIS = 37, TOKEN_KOMENTAR_BANYAK_BARIS = 38, 
                   TOKEN_WHITESPACE = 39;

  @override
  final List<String> ruleNames = [
    'nusantara', 'pernyataan', 'buat_dan_ngisi_variable'
  ];

  static final List<String?> _LITERAL_NAMES = [
      null, "'muat'", "'bilangan bulat'", "'bilangan desimal'", "'karakter'", 
      "'kalimat'", "'bool'", null, null, null, null, null, "'+'", "'-'", 
      "'*'", "'/'", "'%'", "'''", "'\"'", null, "'='", "';'", "'('", "')'", 
      "'{'", "'}'", "'['", "']'", "'<'", "'>'", "'<='", "'>='", "'?'", "'!'", 
      "','", "'.'", "'\$'"
  ];
  static final List<String?> _SYMBOLIC_NAMES = [
      null, "MUAT", "TIPE_DATA_BILANGAN_BULAT", "TIPE_DATA_BILANGAN_DESIMAL", 
      "TIPE_DATA_KARAKTER", "TIPE_DATA_KALIMAT", "TIPE_DATA_BOOLEAN", "NILAI_BILANGAN_BULAT", 
      "NILAI_BILANGAN_DESIMAL", "NILAI_KARAKTER", "NILAI_KALIMAT", "NILAI_BOOLEAN", 
      "TAMBAH", "KURANG", "KALI", "BAGI", "SISA_BAGI", "KUTIP_SATU", "KUTIP_DUA", 
      "IDENTIFIKASI", "SAMA_DENGAN", "TITIK_KOMA", "KURUNG_BUKA", "KURUNG_TUTUP", 
      "KURUNG_KURAWAL_BUKA", "KURUNG_KURAWAL_TUTUP", "KURUNG_SIKU_BUKA", 
      "KURUNG_SIKU_TUTUP", "KURANG_DARI", "LEBIH_BESAR_DARI", "KURANG_DARI_SAMA_DENGAN", 
      "LEBIH_BESAR_DARI_SAMA_DENGAN", "TANDA_TANYA", "TANDA_SERU", "KOMA", 
      "TITIK", "DOLAR", "KOMENTAR_SATU_BARIS", "KOMENTAR_BANYAK_BARIS", 
      "WHITESPACE"
  ];
  static final Vocabulary VOCABULARY = VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

  @override
  Vocabulary get vocabulary {
    return VOCABULARY;
  }

  @override
  String get grammarFileName => 'NusantaraLanguageParser.g4';

  @override
  List<int> get serializedATN => _serializedATN;

  @override
  ATN getATN() {
   return _ATN;
  }

  NusantaraLanguageParser(TokenStream input) : super(input) {
    interpreter = ParserATNSimulator(this, _ATN, _decisionToDFA, _sharedContextCache);
  }

  NusantaraContext nusantara() {
    dynamic _localctx = NusantaraContext(context, state);
    enterRule(_localctx, 0, RULE_nusantara);
    int _la;
    try {
      enterOuterAlt(_localctx, 1);
      state = 9;
      errorHandler.sync(this);
      _la = tokenStream.LA(1)!;
      while ((((_la) & ~0x3f) == 0 && ((1 << _la) & 124) != 0)) {
        state = 6;
        pernyataan();
        state = 11;
        errorHandler.sync(this);
        _la = tokenStream.LA(1)!;
      }
      state = 12;
      match(TOKEN_EOF);
    } on RecognitionException catch (re) {
      _localctx.exception = re;
      errorHandler.reportError(this, re);
      errorHandler.recover(this, re);
    } finally {
      exitRule();
    }
    return _localctx;
  }

  PernyataanContext pernyataan() {
    dynamic _localctx = PernyataanContext(context, state);
    enterRule(_localctx, 2, RULE_pernyataan);
    try {
      _localctx = PernyataanBuatDanNgisiVariableContext(_localctx);
      enterOuterAlt(_localctx, 1);
      state = 14;
      buat_dan_ngisi_variable();
      state = 15;
      match(TOKEN_TITIK_KOMA);
    } on RecognitionException catch (re) {
      _localctx.exception = re;
      errorHandler.reportError(this, re);
      errorHandler.recover(this, re);
    } finally {
      exitRule();
    }
    return _localctx;
  }

  Buat_dan_ngisi_variableContext buat_dan_ngisi_variable() {
    dynamic _localctx = Buat_dan_ngisi_variableContext(context, state);
    enterRule(_localctx, 4, RULE_buat_dan_ngisi_variable);
    try {
      state = 37;
      errorHandler.sync(this);
      switch (tokenStream.LA(1)!) {
      case TOKEN_TIPE_DATA_BILANGAN_BULAT:
        _localctx = BuatDanNgisiVariableBilanganBulatContext(_localctx);
        enterOuterAlt(_localctx, 1);
        state = 17;
        match(TOKEN_TIPE_DATA_BILANGAN_BULAT);
        state = 18;
        match(TOKEN_IDENTIFIKASI);
        state = 19;
        match(TOKEN_SAMA_DENGAN);
        state = 20;
        match(TOKEN_NILAI_BILANGAN_BULAT);
        break;
      case TOKEN_TIPE_DATA_BILANGAN_DESIMAL:
        _localctx = BuatDanNgisiVariableBilanganDesimalContext(_localctx);
        enterOuterAlt(_localctx, 2);
        state = 21;
        match(TOKEN_TIPE_DATA_BILANGAN_DESIMAL);
        state = 22;
        match(TOKEN_IDENTIFIKASI);
        state = 23;
        match(TOKEN_SAMA_DENGAN);
        state = 24;
        match(TOKEN_NILAI_BILANGAN_DESIMAL);
        break;
      case TOKEN_TIPE_DATA_KARAKTER:
        _localctx = BuatDanNgisiVariableKarakterContext(_localctx);
        enterOuterAlt(_localctx, 3);
        state = 25;
        match(TOKEN_TIPE_DATA_KARAKTER);
        state = 26;
        match(TOKEN_IDENTIFIKASI);
        state = 27;
        match(TOKEN_SAMA_DENGAN);
        state = 28;
        match(TOKEN_NILAI_KARAKTER);
        break;
      case TOKEN_TIPE_DATA_KALIMAT:
        _localctx = BuatDanNgisiVariableKalimatContext(_localctx);
        enterOuterAlt(_localctx, 4);
        state = 29;
        match(TOKEN_TIPE_DATA_KALIMAT);
        state = 30;
        match(TOKEN_IDENTIFIKASI);
        state = 31;
        match(TOKEN_SAMA_DENGAN);
        state = 32;
        match(TOKEN_NILAI_KALIMAT);
        break;
      case TOKEN_TIPE_DATA_BOOLEAN:
        _localctx = BuatDanNgisiVariableBooleanContext(_localctx);
        enterOuterAlt(_localctx, 5);
        state = 33;
        match(TOKEN_TIPE_DATA_BOOLEAN);
        state = 34;
        match(TOKEN_IDENTIFIKASI);
        state = 35;
        match(TOKEN_SAMA_DENGAN);
        state = 36;
        match(TOKEN_NILAI_BOOLEAN);
        break;
      default:
        throw NoViableAltException(this);
      }
    } on RecognitionException catch (re) {
      _localctx.exception = re;
      errorHandler.reportError(this, re);
      errorHandler.recover(this, re);
    } finally {
      exitRule();
    }
    return _localctx;
  }

  static const List<int> _serializedATN = [
      4,1,39,40,2,0,7,0,2,1,7,1,2,2,7,2,1,0,5,0,8,8,0,10,0,12,0,11,9,0,1,
      0,1,0,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,
      1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,38,8,2,1,2,0,0,3,0,2,4,0,0,41,
      0,9,1,0,0,0,2,14,1,0,0,0,4,37,1,0,0,0,6,8,3,2,1,0,7,6,1,0,0,0,8,11,
      1,0,0,0,9,7,1,0,0,0,9,10,1,0,0,0,10,12,1,0,0,0,11,9,1,0,0,0,12,13,
      5,0,0,1,13,1,1,0,0,0,14,15,3,4,2,0,15,16,5,21,0,0,16,3,1,0,0,0,17,
      18,5,2,0,0,18,19,5,19,0,0,19,20,5,20,0,0,20,38,5,7,0,0,21,22,5,3,0,
      0,22,23,5,19,0,0,23,24,5,20,0,0,24,38,5,8,0,0,25,26,5,4,0,0,26,27,
      5,19,0,0,27,28,5,20,0,0,28,38,5,9,0,0,29,30,5,5,0,0,30,31,5,19,0,0,
      31,32,5,20,0,0,32,38,5,10,0,0,33,34,5,6,0,0,34,35,5,19,0,0,35,36,5,
      20,0,0,36,38,5,11,0,0,37,17,1,0,0,0,37,21,1,0,0,0,37,25,1,0,0,0,37,
      29,1,0,0,0,37,33,1,0,0,0,38,5,1,0,0,0,2,9,37
  ];

  static final ATN _ATN =
      ATNDeserializer().deserialize(_serializedATN);
}
class NusantaraContext extends ParserRuleContext {
  TerminalNode? EOF() => getToken(NusantaraLanguageParser.TOKEN_EOF, 0);
  List<PernyataanContext> pernyataans() => getRuleContexts<PernyataanContext>();
  PernyataanContext? pernyataan(int i) => getRuleContext<PernyataanContext>(i);
  NusantaraContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_nusantara;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterNusantara(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitNusantara(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitNusantara(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class PernyataanContext extends ParserRuleContext {
  PernyataanContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_pernyataan;
 
  @override
  void copyFrom(ParserRuleContext ctx) {
    super.copyFrom(ctx);
  }
}

class Buat_dan_ngisi_variableContext extends ParserRuleContext {
  Buat_dan_ngisi_variableContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_buat_dan_ngisi_variable;
 
  @override
  void copyFrom(ParserRuleContext ctx) {
    super.copyFrom(ctx);
  }
}

class PernyataanBuatDanNgisiVariableContext extends PernyataanContext {
  Buat_dan_ngisi_variableContext? buat_dan_ngisi_variable() => getRuleContext<Buat_dan_ngisi_variableContext>(0);
  TerminalNode? TITIK_KOMA() => getToken(NusantaraLanguageParser.TOKEN_TITIK_KOMA, 0);
  PernyataanBuatDanNgisiVariableContext(PernyataanContext ctx) { copyFrom(ctx); }
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterPernyataanBuatDanNgisiVariable(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitPernyataanBuatDanNgisiVariable(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitPernyataanBuatDanNgisiVariable(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}class BuatDanNgisiVariableBilanganBulatContext extends Buat_dan_ngisi_variableContext {
  TerminalNode? TIPE_DATA_BILANGAN_BULAT() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_BILANGAN_BULAT, 0);
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  TerminalNode? SAMA_DENGAN() => getToken(NusantaraLanguageParser.TOKEN_SAMA_DENGAN, 0);
  TerminalNode? NILAI_BILANGAN_BULAT() => getToken(NusantaraLanguageParser.TOKEN_NILAI_BILANGAN_BULAT, 0);
  BuatDanNgisiVariableBilanganBulatContext(Buat_dan_ngisi_variableContext ctx) { copyFrom(ctx); }
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterBuatDanNgisiVariableBilanganBulat(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitBuatDanNgisiVariableBilanganBulat(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitBuatDanNgisiVariableBilanganBulat(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class BuatDanNgisiVariableKalimatContext extends Buat_dan_ngisi_variableContext {
  TerminalNode? TIPE_DATA_KALIMAT() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_KALIMAT, 0);
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  TerminalNode? SAMA_DENGAN() => getToken(NusantaraLanguageParser.TOKEN_SAMA_DENGAN, 0);
  TerminalNode? NILAI_KALIMAT() => getToken(NusantaraLanguageParser.TOKEN_NILAI_KALIMAT, 0);
  BuatDanNgisiVariableKalimatContext(Buat_dan_ngisi_variableContext ctx) { copyFrom(ctx); }
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterBuatDanNgisiVariableKalimat(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitBuatDanNgisiVariableKalimat(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitBuatDanNgisiVariableKalimat(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class BuatDanNgisiVariableBooleanContext extends Buat_dan_ngisi_variableContext {
  TerminalNode? TIPE_DATA_BOOLEAN() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_BOOLEAN, 0);
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  TerminalNode? SAMA_DENGAN() => getToken(NusantaraLanguageParser.TOKEN_SAMA_DENGAN, 0);
  TerminalNode? NILAI_BOOLEAN() => getToken(NusantaraLanguageParser.TOKEN_NILAI_BOOLEAN, 0);
  BuatDanNgisiVariableBooleanContext(Buat_dan_ngisi_variableContext ctx) { copyFrom(ctx); }
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterBuatDanNgisiVariableBoolean(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitBuatDanNgisiVariableBoolean(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitBuatDanNgisiVariableBoolean(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class BuatDanNgisiVariableBilanganDesimalContext extends Buat_dan_ngisi_variableContext {
  TerminalNode? TIPE_DATA_BILANGAN_DESIMAL() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_BILANGAN_DESIMAL, 0);
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  TerminalNode? SAMA_DENGAN() => getToken(NusantaraLanguageParser.TOKEN_SAMA_DENGAN, 0);
  TerminalNode? NILAI_BILANGAN_DESIMAL() => getToken(NusantaraLanguageParser.TOKEN_NILAI_BILANGAN_DESIMAL, 0);
  BuatDanNgisiVariableBilanganDesimalContext(Buat_dan_ngisi_variableContext ctx) { copyFrom(ctx); }
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterBuatDanNgisiVariableBilanganDesimal(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitBuatDanNgisiVariableBilanganDesimal(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitBuatDanNgisiVariableBilanganDesimal(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class BuatDanNgisiVariableKarakterContext extends Buat_dan_ngisi_variableContext {
  TerminalNode? TIPE_DATA_KARAKTER() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_KARAKTER, 0);
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  TerminalNode? SAMA_DENGAN() => getToken(NusantaraLanguageParser.TOKEN_SAMA_DENGAN, 0);
  TerminalNode? NILAI_KARAKTER() => getToken(NusantaraLanguageParser.TOKEN_NILAI_KARAKTER, 0);
  BuatDanNgisiVariableKarakterContext(Buat_dan_ngisi_variableContext ctx) { copyFrom(ctx); }
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterBuatDanNgisiVariableKarakter(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitBuatDanNgisiVariableKarakter(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitBuatDanNgisiVariableKarakter(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}