// Generated from /home/aerell/nusantara/grammar/NusantaraLanguageParser.g4 by ANTLR 4.13.1
// ignore_for_file: unused_import, unused_local_variable, prefer_single_quotes
import 'package:antlr4/antlr4.dart';

import 'NusantaraLanguageParserListener.dart';
import 'NusantaraLanguageParserBaseListener.dart';
import 'NusantaraLanguageParserVisitor.dart';
import 'NusantaraLanguageParserBaseVisitor.dart';
const int RULE_nusantara = 0, RULE_pernyataan = 1, RULE_komentar = 2, RULE_muat_file = 3, 
          RULE_blok_kode = 4, RULE_parameter_fungsi_kosong = 5, RULE_parameter_buat_fungsi = 6, 
          RULE_buat_fungsi = 7, RULE_parameter_panggil_fungsi = 8, RULE_panggil_fungsi = 9, 
          RULE_tipe_data_variable = 10, RULE_buat_variable = 11, RULE_nilai_variable = 12, 
          RULE_ngisi_variable = 13, RULE_buat_dan_ngisi_variable = 14;
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
    'nusantara', 'pernyataan', 'komentar', 'muat_file', 'blok_kode', 'parameter_fungsi_kosong', 
    'parameter_buat_fungsi', 'buat_fungsi', 'parameter_panggil_fungsi', 
    'panggil_fungsi', 'tipe_data_variable', 'buat_variable', 'nilai_variable', 
    'ngisi_variable', 'buat_dan_ngisi_variable'
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
      state = 37;
      errorHandler.sync(this);
      switch (interpreter!.adaptivePredict(tokenStream, 1, context)) {
      case 1:
        enterOuterAlt(_localctx, 1);
        state = 33;
        errorHandler.sync(this);
        _la = tokenStream.LA(1)!;
        while ((((_la) & ~0x3f) == 0 && ((1 << _la) & 412334162046) != 0)) {
          state = 30;
          pernyataan();
          state = 35;
          errorHandler.sync(this);
          _la = tokenStream.LA(1)!;
        }
        break;
      case 2:
        enterOuterAlt(_localctx, 2);
        state = 36;
        match(TOKEN_EOF);
        break;
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

  PernyataanContext pernyataan() {
    dynamic _localctx = PernyataanContext(context, state);
    enterRule(_localctx, 2, RULE_pernyataan);
    try {
      state = 57;
      errorHandler.sync(this);
      switch (interpreter!.adaptivePredict(tokenStream, 2, context)) {
      case 1:
        enterOuterAlt(_localctx, 1);
        state = 39;
        komentar();
        break;
      case 2:
        enterOuterAlt(_localctx, 2);
        state = 40;
        blok_kode();
        break;
      case 3:
        enterOuterAlt(_localctx, 3);
        state = 41;
        buat_fungsi();
        break;
      case 4:
        enterOuterAlt(_localctx, 4);
        state = 42;
        muat_file();
        state = 43;
        match(TOKEN_TITIK_KOMA);
        break;
      case 5:
        enterOuterAlt(_localctx, 5);
        state = 45;
        panggil_fungsi();
        state = 46;
        match(TOKEN_TITIK_KOMA);
        break;
      case 6:
        enterOuterAlt(_localctx, 6);
        state = 48;
        buat_variable();
        state = 49;
        match(TOKEN_TITIK_KOMA);
        break;
      case 7:
        enterOuterAlt(_localctx, 7);
        state = 51;
        ngisi_variable();
        state = 52;
        match(TOKEN_TITIK_KOMA);
        break;
      case 8:
        enterOuterAlt(_localctx, 8);
        state = 54;
        buat_dan_ngisi_variable();
        state = 55;
        match(TOKEN_TITIK_KOMA);
        break;
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

  KomentarContext komentar() {
    dynamic _localctx = KomentarContext(context, state);
    enterRule(_localctx, 4, RULE_komentar);
    int _la;
    try {
      enterOuterAlt(_localctx, 1);
      state = 59;
      _la = tokenStream.LA(1)!;
      if (!(_la == TOKEN_KOMENTAR_SATU_BARIS || _la == TOKEN_KOMENTAR_BANYAK_BARIS)) {
      errorHandler.recoverInline(this);
      } else {
        if ( tokenStream.LA(1)! == IntStream.EOF ) matchedEOF = true;
        errorHandler.reportMatch(this);
        consume();
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

  Muat_fileContext muat_file() {
    dynamic _localctx = Muat_fileContext(context, state);
    enterRule(_localctx, 6, RULE_muat_file);
    try {
      enterOuterAlt(_localctx, 1);
      state = 61;
      match(TOKEN_MUAT);
      state = 62;
      match(TOKEN_NILAI_KALIMAT);
    } on RecognitionException catch (re) {
      _localctx.exception = re;
      errorHandler.reportError(this, re);
      errorHandler.recover(this, re);
    } finally {
      exitRule();
    }
    return _localctx;
  }

  Blok_kodeContext blok_kode() {
    dynamic _localctx = Blok_kodeContext(context, state);
    enterRule(_localctx, 8, RULE_blok_kode);
    int _la;
    try {
      enterOuterAlt(_localctx, 1);
      state = 64;
      match(TOKEN_KURUNG_KURAWAL_BUKA);
      state = 68;
      errorHandler.sync(this);
      _la = tokenStream.LA(1)!;
      while ((((_la) & ~0x3f) == 0 && ((1 << _la) & 412334162046) != 0)) {
        state = 65;
        pernyataan();
        state = 70;
        errorHandler.sync(this);
        _la = tokenStream.LA(1)!;
      }
      state = 71;
      match(TOKEN_KURUNG_KURAWAL_TUTUP);
    } on RecognitionException catch (re) {
      _localctx.exception = re;
      errorHandler.reportError(this, re);
      errorHandler.recover(this, re);
    } finally {
      exitRule();
    }
    return _localctx;
  }

  Parameter_fungsi_kosongContext parameter_fungsi_kosong() {
    dynamic _localctx = Parameter_fungsi_kosongContext(context, state);
    enterRule(_localctx, 10, RULE_parameter_fungsi_kosong);
    try {
      enterOuterAlt(_localctx, 1);
      state = 73;
      match(TOKEN_KURUNG_BUKA);
      state = 74;
      match(TOKEN_KURUNG_TUTUP);
    } on RecognitionException catch (re) {
      _localctx.exception = re;
      errorHandler.reportError(this, re);
      errorHandler.recover(this, re);
    } finally {
      exitRule();
    }
    return _localctx;
  }

  Parameter_buat_fungsiContext parameter_buat_fungsi() {
    dynamic _localctx = Parameter_buat_fungsiContext(context, state);
    enterRule(_localctx, 12, RULE_parameter_buat_fungsi);
    int _la;
    try {
      state = 94;
      errorHandler.sync(this);
      switch (interpreter!.adaptivePredict(tokenStream, 8, context)) {
      case 1:
        enterOuterAlt(_localctx, 1);
        state = 76;
        parameter_fungsi_kosong();
        break;
      case 2:
        enterOuterAlt(_localctx, 2);
        state = 77;
        match(TOKEN_KURUNG_BUKA);
        state = 80;
        errorHandler.sync(this);
        switch (interpreter!.adaptivePredict(tokenStream, 4, context)) {
        case 1:
          state = 78;
          buat_variable();
          break;
        case 2:
          state = 79;
          buat_dan_ngisi_variable();
          break;
        }
        state = 90;
        errorHandler.sync(this);
        _la = tokenStream.LA(1)!;
        if (_la == TOKEN_KOMA) {
          state = 82;
          match(TOKEN_KOMA);
          state = 87;
          errorHandler.sync(this);
          _la = tokenStream.LA(1)!;
          while ((((_la) & ~0x3f) == 0 && ((1 << _la) & 124) != 0)) {
            state = 85;
            errorHandler.sync(this);
            switch (interpreter!.adaptivePredict(tokenStream, 5, context)) {
            case 1:
              state = 83;
              buat_variable();
              break;
            case 2:
              state = 84;
              buat_dan_ngisi_variable();
              break;
            }
            state = 89;
            errorHandler.sync(this);
            _la = tokenStream.LA(1)!;
          }
        }

        state = 92;
        match(TOKEN_KURUNG_TUTUP);
        break;
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

  Buat_fungsiContext buat_fungsi() {
    dynamic _localctx = Buat_fungsiContext(context, state);
    enterRule(_localctx, 14, RULE_buat_fungsi);
    try {
      enterOuterAlt(_localctx, 1);
      state = 96;
      match(TOKEN_IDENTIFIKASI);
      state = 97;
      parameter_buat_fungsi();
      state = 98;
      blok_kode();
    } on RecognitionException catch (re) {
      _localctx.exception = re;
      errorHandler.reportError(this, re);
      errorHandler.recover(this, re);
    } finally {
      exitRule();
    }
    return _localctx;
  }

  Parameter_panggil_fungsiContext parameter_panggil_fungsi() {
    dynamic _localctx = Parameter_panggil_fungsiContext(context, state);
    enterRule(_localctx, 16, RULE_parameter_panggil_fungsi);
    int _la;
    try {
      state = 114;
      errorHandler.sync(this);
      switch (interpreter!.adaptivePredict(tokenStream, 11, context)) {
      case 1:
        enterOuterAlt(_localctx, 1);
        state = 100;
        parameter_fungsi_kosong();
        break;
      case 2:
        enterOuterAlt(_localctx, 2);
        state = 101;
        match(TOKEN_KURUNG_BUKA);

        state = 102;
        nilai_variable();
        state = 110;
        errorHandler.sync(this);
        _la = tokenStream.LA(1)!;
        if (_la == TOKEN_KOMA) {
          state = 103;
          match(TOKEN_KOMA);
          state = 107;
          errorHandler.sync(this);
          _la = tokenStream.LA(1)!;
          while ((((_la) & ~0x3f) == 0 && ((1 << _la) & 3968) != 0)) {
            state = 104;
            nilai_variable();
            state = 109;
            errorHandler.sync(this);
            _la = tokenStream.LA(1)!;
          }
        }

        state = 112;
        match(TOKEN_KURUNG_TUTUP);
        break;
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

  Panggil_fungsiContext panggil_fungsi() {
    dynamic _localctx = Panggil_fungsiContext(context, state);
    enterRule(_localctx, 18, RULE_panggil_fungsi);
    try {
      enterOuterAlt(_localctx, 1);
      state = 116;
      match(TOKEN_IDENTIFIKASI);
      state = 117;
      parameter_panggil_fungsi();
    } on RecognitionException catch (re) {
      _localctx.exception = re;
      errorHandler.reportError(this, re);
      errorHandler.recover(this, re);
    } finally {
      exitRule();
    }
    return _localctx;
  }

  Tipe_data_variableContext tipe_data_variable() {
    dynamic _localctx = Tipe_data_variableContext(context, state);
    enterRule(_localctx, 20, RULE_tipe_data_variable);
    int _la;
    try {
      enterOuterAlt(_localctx, 1);
      state = 119;
      _la = tokenStream.LA(1)!;
      if (!((((_la) & ~0x3f) == 0 && ((1 << _la) & 124) != 0))) {
      errorHandler.recoverInline(this);
      } else {
        if ( tokenStream.LA(1)! == IntStream.EOF ) matchedEOF = true;
        errorHandler.reportMatch(this);
        consume();
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

  Buat_variableContext buat_variable() {
    dynamic _localctx = Buat_variableContext(context, state);
    enterRule(_localctx, 22, RULE_buat_variable);
    try {
      enterOuterAlt(_localctx, 1);
      state = 121;
      tipe_data_variable();
      state = 122;
      match(TOKEN_IDENTIFIKASI);
    } on RecognitionException catch (re) {
      _localctx.exception = re;
      errorHandler.reportError(this, re);
      errorHandler.recover(this, re);
    } finally {
      exitRule();
    }
    return _localctx;
  }

  Nilai_variableContext nilai_variable() {
    dynamic _localctx = Nilai_variableContext(context, state);
    enterRule(_localctx, 24, RULE_nilai_variable);
    int _la;
    try {
      enterOuterAlt(_localctx, 1);
      state = 124;
      _la = tokenStream.LA(1)!;
      if (!((((_la) & ~0x3f) == 0 && ((1 << _la) & 3968) != 0))) {
      errorHandler.recoverInline(this);
      } else {
        if ( tokenStream.LA(1)! == IntStream.EOF ) matchedEOF = true;
        errorHandler.reportMatch(this);
        consume();
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

  Ngisi_variableContext ngisi_variable() {
    dynamic _localctx = Ngisi_variableContext(context, state);
    enterRule(_localctx, 26, RULE_ngisi_variable);
    try {
      enterOuterAlt(_localctx, 1);
      state = 126;
      match(TOKEN_IDENTIFIKASI);
      state = 127;
      match(TOKEN_SAMA_DENGAN);
      state = 128;
      nilai_variable();
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
    enterRule(_localctx, 28, RULE_buat_dan_ngisi_variable);
    try {
      state = 150;
      errorHandler.sync(this);
      switch (tokenStream.LA(1)!) {
      case TOKEN_TIPE_DATA_BILANGAN_BULAT:
        enterOuterAlt(_localctx, 1);
        state = 130;
        match(TOKEN_TIPE_DATA_BILANGAN_BULAT);
        state = 131;
        match(TOKEN_IDENTIFIKASI);
        state = 132;
        match(TOKEN_SAMA_DENGAN);
        state = 133;
        match(TOKEN_NILAI_BILANGAN_BULAT);
        break;
      case TOKEN_TIPE_DATA_BILANGAN_DESIMAL:
        enterOuterAlt(_localctx, 2);
        state = 134;
        match(TOKEN_TIPE_DATA_BILANGAN_DESIMAL);
        state = 135;
        match(TOKEN_IDENTIFIKASI);
        state = 136;
        match(TOKEN_SAMA_DENGAN);
        state = 137;
        match(TOKEN_NILAI_BILANGAN_DESIMAL);
        break;
      case TOKEN_TIPE_DATA_KARAKTER:
        enterOuterAlt(_localctx, 3);
        state = 138;
        match(TOKEN_TIPE_DATA_KARAKTER);
        state = 139;
        match(TOKEN_IDENTIFIKASI);
        state = 140;
        match(TOKEN_SAMA_DENGAN);
        state = 141;
        match(TOKEN_NILAI_KARAKTER);
        break;
      case TOKEN_TIPE_DATA_KALIMAT:
        enterOuterAlt(_localctx, 4);
        state = 142;
        match(TOKEN_TIPE_DATA_KALIMAT);
        state = 143;
        match(TOKEN_IDENTIFIKASI);
        state = 144;
        match(TOKEN_SAMA_DENGAN);
        state = 145;
        match(TOKEN_NILAI_KALIMAT);
        break;
      case TOKEN_TIPE_DATA_BOOLEAN:
        enterOuterAlt(_localctx, 5);
        state = 146;
        match(TOKEN_TIPE_DATA_BOOLEAN);
        state = 147;
        match(TOKEN_IDENTIFIKASI);
        state = 148;
        match(TOKEN_SAMA_DENGAN);
        state = 149;
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
      4,1,39,153,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,
      2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,
      14,7,14,1,0,5,0,32,8,0,10,0,12,0,35,9,0,1,0,3,0,38,8,0,1,1,1,1,1,1,
      1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,58,
      8,1,1,2,1,2,1,3,1,3,1,3,1,4,1,4,5,4,67,8,4,10,4,12,4,70,9,4,1,4,1,
      4,1,5,1,5,1,5,1,6,1,6,1,6,1,6,3,6,81,8,6,1,6,1,6,1,6,5,6,86,8,6,10,
      6,12,6,89,9,6,3,6,91,8,6,1,6,1,6,3,6,95,8,6,1,7,1,7,1,7,1,7,1,8,1,
      8,1,8,1,8,1,8,5,8,106,8,8,10,8,12,8,109,9,8,3,8,111,8,8,1,8,1,8,3,
      8,115,8,8,1,9,1,9,1,9,1,10,1,10,1,11,1,11,1,11,1,12,1,12,1,13,1,13,
      1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
      14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,151,8,14,1,14,0,0,
      15,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,0,3,1,0,37,38,1,0,2,6,1,
      0,7,11,159,0,37,1,0,0,0,2,57,1,0,0,0,4,59,1,0,0,0,6,61,1,0,0,0,8,64,
      1,0,0,0,10,73,1,0,0,0,12,94,1,0,0,0,14,96,1,0,0,0,16,114,1,0,0,0,18,
      116,1,0,0,0,20,119,1,0,0,0,22,121,1,0,0,0,24,124,1,0,0,0,26,126,1,
      0,0,0,28,150,1,0,0,0,30,32,3,2,1,0,31,30,1,0,0,0,32,35,1,0,0,0,33,
      31,1,0,0,0,33,34,1,0,0,0,34,38,1,0,0,0,35,33,1,0,0,0,36,38,5,0,0,1,
      37,33,1,0,0,0,37,36,1,0,0,0,38,1,1,0,0,0,39,58,3,4,2,0,40,58,3,8,4,
      0,41,58,3,14,7,0,42,43,3,6,3,0,43,44,5,21,0,0,44,58,1,0,0,0,45,46,
      3,18,9,0,46,47,5,21,0,0,47,58,1,0,0,0,48,49,3,22,11,0,49,50,5,21,0,
      0,50,58,1,0,0,0,51,52,3,26,13,0,52,53,5,21,0,0,53,58,1,0,0,0,54,55,
      3,28,14,0,55,56,5,21,0,0,56,58,1,0,0,0,57,39,1,0,0,0,57,40,1,0,0,0,
      57,41,1,0,0,0,57,42,1,0,0,0,57,45,1,0,0,0,57,48,1,0,0,0,57,51,1,0,
      0,0,57,54,1,0,0,0,58,3,1,0,0,0,59,60,7,0,0,0,60,5,1,0,0,0,61,62,5,
      1,0,0,62,63,5,10,0,0,63,7,1,0,0,0,64,68,5,24,0,0,65,67,3,2,1,0,66,
      65,1,0,0,0,67,70,1,0,0,0,68,66,1,0,0,0,68,69,1,0,0,0,69,71,1,0,0,0,
      70,68,1,0,0,0,71,72,5,25,0,0,72,9,1,0,0,0,73,74,5,22,0,0,74,75,5,23,
      0,0,75,11,1,0,0,0,76,95,3,10,5,0,77,80,5,22,0,0,78,81,3,22,11,0,79,
      81,3,28,14,0,80,78,1,0,0,0,80,79,1,0,0,0,81,90,1,0,0,0,82,87,5,34,
      0,0,83,86,3,22,11,0,84,86,3,28,14,0,85,83,1,0,0,0,85,84,1,0,0,0,86,
      89,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,91,1,0,0,0,89,87,1,0,0,0,
      90,82,1,0,0,0,90,91,1,0,0,0,91,92,1,0,0,0,92,93,5,23,0,0,93,95,1,0,
      0,0,94,76,1,0,0,0,94,77,1,0,0,0,95,13,1,0,0,0,96,97,5,19,0,0,97,98,
      3,12,6,0,98,99,3,8,4,0,99,15,1,0,0,0,100,115,3,10,5,0,101,102,5,22,
      0,0,102,110,3,24,12,0,103,107,5,34,0,0,104,106,3,24,12,0,105,104,1,
      0,0,0,106,109,1,0,0,0,107,105,1,0,0,0,107,108,1,0,0,0,108,111,1,0,
      0,0,109,107,1,0,0,0,110,103,1,0,0,0,110,111,1,0,0,0,111,112,1,0,0,
      0,112,113,5,23,0,0,113,115,1,0,0,0,114,100,1,0,0,0,114,101,1,0,0,0,
      115,17,1,0,0,0,116,117,5,19,0,0,117,118,3,16,8,0,118,19,1,0,0,0,119,
      120,7,1,0,0,120,21,1,0,0,0,121,122,3,20,10,0,122,123,5,19,0,0,123,
      23,1,0,0,0,124,125,7,2,0,0,125,25,1,0,0,0,126,127,5,19,0,0,127,128,
      5,20,0,0,128,129,3,24,12,0,129,27,1,0,0,0,130,131,5,2,0,0,131,132,
      5,19,0,0,132,133,5,20,0,0,133,151,5,7,0,0,134,135,5,3,0,0,135,136,
      5,19,0,0,136,137,5,20,0,0,137,151,5,8,0,0,138,139,5,4,0,0,139,140,
      5,19,0,0,140,141,5,20,0,0,141,151,5,9,0,0,142,143,5,5,0,0,143,144,
      5,19,0,0,144,145,5,20,0,0,145,151,5,10,0,0,146,147,5,6,0,0,147,148,
      5,19,0,0,148,149,5,20,0,0,149,151,5,11,0,0,150,130,1,0,0,0,150,134,
      1,0,0,0,150,138,1,0,0,0,150,142,1,0,0,0,150,146,1,0,0,0,151,29,1,0,
      0,0,13,33,37,57,68,80,85,87,90,94,107,110,114,150
  ];

  static final ATN _ATN =
      ATNDeserializer().deserialize(_serializedATN);
}
class NusantaraContext extends ParserRuleContext {
  List<PernyataanContext> pernyataans() => getRuleContexts<PernyataanContext>();
  PernyataanContext? pernyataan(int i) => getRuleContext<PernyataanContext>(i);
  TerminalNode? EOF() => getToken(NusantaraLanguageParser.TOKEN_EOF, 0);
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
  KomentarContext? komentar() => getRuleContext<KomentarContext>(0);
  Blok_kodeContext? blok_kode() => getRuleContext<Blok_kodeContext>(0);
  Buat_fungsiContext? buat_fungsi() => getRuleContext<Buat_fungsiContext>(0);
  Muat_fileContext? muat_file() => getRuleContext<Muat_fileContext>(0);
  TerminalNode? TITIK_KOMA() => getToken(NusantaraLanguageParser.TOKEN_TITIK_KOMA, 0);
  Panggil_fungsiContext? panggil_fungsi() => getRuleContext<Panggil_fungsiContext>(0);
  Buat_variableContext? buat_variable() => getRuleContext<Buat_variableContext>(0);
  Ngisi_variableContext? ngisi_variable() => getRuleContext<Ngisi_variableContext>(0);
  Buat_dan_ngisi_variableContext? buat_dan_ngisi_variable() => getRuleContext<Buat_dan_ngisi_variableContext>(0);
  PernyataanContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_pernyataan;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterPernyataan(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitPernyataan(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitPernyataan(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class KomentarContext extends ParserRuleContext {
  TerminalNode? KOMENTAR_SATU_BARIS() => getToken(NusantaraLanguageParser.TOKEN_KOMENTAR_SATU_BARIS, 0);
  TerminalNode? KOMENTAR_BANYAK_BARIS() => getToken(NusantaraLanguageParser.TOKEN_KOMENTAR_BANYAK_BARIS, 0);
  KomentarContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_komentar;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterKomentar(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitKomentar(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitKomentar(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Muat_fileContext extends ParserRuleContext {
  TerminalNode? MUAT() => getToken(NusantaraLanguageParser.TOKEN_MUAT, 0);
  TerminalNode? NILAI_KALIMAT() => getToken(NusantaraLanguageParser.TOKEN_NILAI_KALIMAT, 0);
  Muat_fileContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_muat_file;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterMuat_file(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitMuat_file(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitMuat_file(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Blok_kodeContext extends ParserRuleContext {
  TerminalNode? KURUNG_KURAWAL_BUKA() => getToken(NusantaraLanguageParser.TOKEN_KURUNG_KURAWAL_BUKA, 0);
  TerminalNode? KURUNG_KURAWAL_TUTUP() => getToken(NusantaraLanguageParser.TOKEN_KURUNG_KURAWAL_TUTUP, 0);
  List<PernyataanContext> pernyataans() => getRuleContexts<PernyataanContext>();
  PernyataanContext? pernyataan(int i) => getRuleContext<PernyataanContext>(i);
  Blok_kodeContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_blok_kode;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterBlok_kode(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitBlok_kode(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitBlok_kode(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Parameter_fungsi_kosongContext extends ParserRuleContext {
  TerminalNode? KURUNG_BUKA() => getToken(NusantaraLanguageParser.TOKEN_KURUNG_BUKA, 0);
  TerminalNode? KURUNG_TUTUP() => getToken(NusantaraLanguageParser.TOKEN_KURUNG_TUTUP, 0);
  Parameter_fungsi_kosongContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_parameter_fungsi_kosong;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterParameter_fungsi_kosong(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitParameter_fungsi_kosong(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitParameter_fungsi_kosong(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Parameter_buat_fungsiContext extends ParserRuleContext {
  Parameter_fungsi_kosongContext? parameter_fungsi_kosong() => getRuleContext<Parameter_fungsi_kosongContext>(0);
  TerminalNode? KURUNG_BUKA() => getToken(NusantaraLanguageParser.TOKEN_KURUNG_BUKA, 0);
  TerminalNode? KURUNG_TUTUP() => getToken(NusantaraLanguageParser.TOKEN_KURUNG_TUTUP, 0);
  List<Buat_variableContext> buat_variables() => getRuleContexts<Buat_variableContext>();
  Buat_variableContext? buat_variable(int i) => getRuleContext<Buat_variableContext>(i);
  List<Buat_dan_ngisi_variableContext> buat_dan_ngisi_variables() => getRuleContexts<Buat_dan_ngisi_variableContext>();
  Buat_dan_ngisi_variableContext? buat_dan_ngisi_variable(int i) => getRuleContext<Buat_dan_ngisi_variableContext>(i);
  TerminalNode? KOMA() => getToken(NusantaraLanguageParser.TOKEN_KOMA, 0);
  Parameter_buat_fungsiContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_parameter_buat_fungsi;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterParameter_buat_fungsi(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitParameter_buat_fungsi(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitParameter_buat_fungsi(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Buat_fungsiContext extends ParserRuleContext {
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  Parameter_buat_fungsiContext? parameter_buat_fungsi() => getRuleContext<Parameter_buat_fungsiContext>(0);
  Blok_kodeContext? blok_kode() => getRuleContext<Blok_kodeContext>(0);
  Buat_fungsiContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_buat_fungsi;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterBuat_fungsi(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitBuat_fungsi(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitBuat_fungsi(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Parameter_panggil_fungsiContext extends ParserRuleContext {
  Parameter_fungsi_kosongContext? parameter_fungsi_kosong() => getRuleContext<Parameter_fungsi_kosongContext>(0);
  TerminalNode? KURUNG_BUKA() => getToken(NusantaraLanguageParser.TOKEN_KURUNG_BUKA, 0);
  TerminalNode? KURUNG_TUTUP() => getToken(NusantaraLanguageParser.TOKEN_KURUNG_TUTUP, 0);
  List<Nilai_variableContext> nilai_variables() => getRuleContexts<Nilai_variableContext>();
  Nilai_variableContext? nilai_variable(int i) => getRuleContext<Nilai_variableContext>(i);
  TerminalNode? KOMA() => getToken(NusantaraLanguageParser.TOKEN_KOMA, 0);
  Parameter_panggil_fungsiContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_parameter_panggil_fungsi;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterParameter_panggil_fungsi(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitParameter_panggil_fungsi(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitParameter_panggil_fungsi(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Panggil_fungsiContext extends ParserRuleContext {
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  Parameter_panggil_fungsiContext? parameter_panggil_fungsi() => getRuleContext<Parameter_panggil_fungsiContext>(0);
  Panggil_fungsiContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_panggil_fungsi;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterPanggil_fungsi(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitPanggil_fungsi(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitPanggil_fungsi(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Tipe_data_variableContext extends ParserRuleContext {
  TerminalNode? TIPE_DATA_BILANGAN_BULAT() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_BILANGAN_BULAT, 0);
  TerminalNode? TIPE_DATA_BILANGAN_DESIMAL() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_BILANGAN_DESIMAL, 0);
  TerminalNode? TIPE_DATA_KARAKTER() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_KARAKTER, 0);
  TerminalNode? TIPE_DATA_KALIMAT() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_KALIMAT, 0);
  TerminalNode? TIPE_DATA_BOOLEAN() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_BOOLEAN, 0);
  Tipe_data_variableContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_tipe_data_variable;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterTipe_data_variable(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitTipe_data_variable(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitTipe_data_variable(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Buat_variableContext extends ParserRuleContext {
  Tipe_data_variableContext? tipe_data_variable() => getRuleContext<Tipe_data_variableContext>(0);
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  Buat_variableContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_buat_variable;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterBuat_variable(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitBuat_variable(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitBuat_variable(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Nilai_variableContext extends ParserRuleContext {
  TerminalNode? NILAI_BILANGAN_BULAT() => getToken(NusantaraLanguageParser.TOKEN_NILAI_BILANGAN_BULAT, 0);
  TerminalNode? NILAI_BILANGAN_DESIMAL() => getToken(NusantaraLanguageParser.TOKEN_NILAI_BILANGAN_DESIMAL, 0);
  TerminalNode? NILAI_KARAKTER() => getToken(NusantaraLanguageParser.TOKEN_NILAI_KARAKTER, 0);
  TerminalNode? NILAI_KALIMAT() => getToken(NusantaraLanguageParser.TOKEN_NILAI_KALIMAT, 0);
  TerminalNode? NILAI_BOOLEAN() => getToken(NusantaraLanguageParser.TOKEN_NILAI_BOOLEAN, 0);
  Nilai_variableContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_nilai_variable;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterNilai_variable(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitNilai_variable(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitNilai_variable(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Ngisi_variableContext extends ParserRuleContext {
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  TerminalNode? SAMA_DENGAN() => getToken(NusantaraLanguageParser.TOKEN_SAMA_DENGAN, 0);
  Nilai_variableContext? nilai_variable() => getRuleContext<Nilai_variableContext>(0);
  Ngisi_variableContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_ngisi_variable;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterNgisi_variable(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitNgisi_variable(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitNgisi_variable(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

class Buat_dan_ngisi_variableContext extends ParserRuleContext {
  TerminalNode? TIPE_DATA_BILANGAN_BULAT() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_BILANGAN_BULAT, 0);
  TerminalNode? IDENTIFIKASI() => getToken(NusantaraLanguageParser.TOKEN_IDENTIFIKASI, 0);
  TerminalNode? SAMA_DENGAN() => getToken(NusantaraLanguageParser.TOKEN_SAMA_DENGAN, 0);
  TerminalNode? NILAI_BILANGAN_BULAT() => getToken(NusantaraLanguageParser.TOKEN_NILAI_BILANGAN_BULAT, 0);
  TerminalNode? TIPE_DATA_BILANGAN_DESIMAL() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_BILANGAN_DESIMAL, 0);
  TerminalNode? NILAI_BILANGAN_DESIMAL() => getToken(NusantaraLanguageParser.TOKEN_NILAI_BILANGAN_DESIMAL, 0);
  TerminalNode? TIPE_DATA_KARAKTER() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_KARAKTER, 0);
  TerminalNode? NILAI_KARAKTER() => getToken(NusantaraLanguageParser.TOKEN_NILAI_KARAKTER, 0);
  TerminalNode? TIPE_DATA_KALIMAT() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_KALIMAT, 0);
  TerminalNode? NILAI_KALIMAT() => getToken(NusantaraLanguageParser.TOKEN_NILAI_KALIMAT, 0);
  TerminalNode? TIPE_DATA_BOOLEAN() => getToken(NusantaraLanguageParser.TOKEN_TIPE_DATA_BOOLEAN, 0);
  TerminalNode? NILAI_BOOLEAN() => getToken(NusantaraLanguageParser.TOKEN_NILAI_BOOLEAN, 0);
  Buat_dan_ngisi_variableContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_buat_dan_ngisi_variable;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterBuat_dan_ngisi_variable(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitBuat_dan_ngisi_variable(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitBuat_dan_ngisi_variable(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

