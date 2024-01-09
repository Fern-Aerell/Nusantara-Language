// this file is generated with a generator

import 'package:nusantara/lexer/token_type_data.dart';

enum TokenType {
  WHITESPACE,
  NEWLINE,
  KOMENTAR_SATU_BARIS,
  KOMENTAR_DUA_BARIS,
  TIPE_DATA_BILANGAN_BULAT,
  TIPE_DATA_BILANGAN_DESIMAL,
  TIPE_DATA_KARAKTER,
  TIPE_DATA_KALIMAT,
  TIPE_DATA_BOOLEAN,
  NILAI_BILANGAN_BULAT,
  NILAI_BILANGAN_DESIMAL,
  NILAI_KARAKTER,
  NILAI_KALIMAT,
  NILAI_BOOLEAN,
  SAMA_DENGAN,
  TITIK_KOMA,
  KOMA,
  IDENTIFIKASI;
  @override
  String toString() {
    return name;
  }
}

List<TokenTypeData> tokenTypeData = [
  TokenTypeData(enumTokenType: TokenType.WHITESPACE, rule: RegExp("[ \t\r\f]+", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: true),
  TokenTypeData(enumTokenType: TokenType.NEWLINE, rule: RegExp("\n", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: true),
  TokenTypeData(enumTokenType: TokenType.KOMENTAR_SATU_BARIS, rule: RegExp("//.*", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: true),
  TokenTypeData(enumTokenType: TokenType.KOMENTAR_DUA_BARIS, rule: RegExp("/\\*.*?\\*/", multiLine: true, dotAll: true, caseSensitive: true, unicode: false), skip: true),
  TokenTypeData(enumTokenType: TokenType.TIPE_DATA_BILANGAN_BULAT, rule: RegExp("bilangan bulat", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.TIPE_DATA_BILANGAN_DESIMAL, rule: RegExp("bilangan desimal", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.TIPE_DATA_KARAKTER, rule: RegExp("karakter", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.TIPE_DATA_KALIMAT, rule: RegExp("kalimat", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.TIPE_DATA_BOOLEAN, rule: RegExp("bool", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.NILAI_BILANGAN_BULAT, rule: RegExp("-?[0-9]+", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.NILAI_BILANGAN_DESIMAL, rule: RegExp("-?[0-9]+,[0-9]+", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.NILAI_KARAKTER, rule: RegExp("(\".\")|('.')", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.NILAI_KALIMAT, rule: RegExp("(\".*?\")|('.*?')", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.NILAI_BOOLEAN, rule: RegExp("benar | salah", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.SAMA_DENGAN, rule: RegExp("=", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.TITIK_KOMA, rule: RegExp(";", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.KOMA, rule: RegExp(",", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false),
  TokenTypeData(enumTokenType: TokenType.IDENTIFIKASI, rule: RegExp("[a-zA-Z_]+[a-zA-Z0-9_]*", multiLine: false, dotAll: false, caseSensitive: true, unicode: false), skip: false)
];

TokenType stringToTokenType(String name) {
  switch(name) {
    case "WHITESPACE":
      return TokenType.WHITESPACE;
    case "NEWLINE":
      return TokenType.NEWLINE;
    case "KOMENTAR_SATU_BARIS":
      return TokenType.KOMENTAR_SATU_BARIS;
    case "KOMENTAR_DUA_BARIS":
      return TokenType.KOMENTAR_DUA_BARIS;
    case "TIPE_DATA_BILANGAN_BULAT":
      return TokenType.TIPE_DATA_BILANGAN_BULAT;
    case "TIPE_DATA_BILANGAN_DESIMAL":
      return TokenType.TIPE_DATA_BILANGAN_DESIMAL;
    case "TIPE_DATA_KARAKTER":
      return TokenType.TIPE_DATA_KARAKTER;
    case "TIPE_DATA_KALIMAT":
      return TokenType.TIPE_DATA_KALIMAT;
    case "TIPE_DATA_BOOLEAN":
      return TokenType.TIPE_DATA_BOOLEAN;
    case "NILAI_BILANGAN_BULAT":
      return TokenType.NILAI_BILANGAN_BULAT;
    case "NILAI_BILANGAN_DESIMAL":
      return TokenType.NILAI_BILANGAN_DESIMAL;
    case "NILAI_KARAKTER":
      return TokenType.NILAI_KARAKTER;
    case "NILAI_KALIMAT":
      return TokenType.NILAI_KALIMAT;
    case "NILAI_BOOLEAN":
      return TokenType.NILAI_BOOLEAN;
    case "SAMA_DENGAN":
      return TokenType.SAMA_DENGAN;
    case "TITIK_KOMA":
      return TokenType.TITIK_KOMA;
    case "KOMA":
      return TokenType.KOMA;
    case "IDENTIFIKASI":
      return TokenType.IDENTIFIKASI;
    default:
      throw "Tidak ada tipe token dengan nama $name";
  }
}

TokenTypeData enumToTokenTypeData(TokenType type) {
  return tokenTypeData.firstWhere((element) => element.enumTokenType == type);
}

// End of file.