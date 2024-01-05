// Generated from /home/aerell/nusantara/grammar/NusantaraLanguageParser.g4 by ANTLR 4.13.1
// ignore_for_file: unused_import, unused_local_variable, prefer_single_quotes
import 'package:antlr4/antlr4.dart';

import 'NusantaraLanguageParserListener.dart';
import 'NusantaraLanguageParserBaseListener.dart';
import 'NusantaraLanguageParserVisitor.dart';
import 'NusantaraLanguageParserBaseVisitor.dart';
const int RULE_awal = 0;
class NusantaraLanguageParser extends Parser {
  static final checkVersion = () => RuntimeMetaData.checkVersion('4.13.1', RuntimeMetaData.VERSION);
  static const int TOKEN_EOF = IntStream.EOF;

  static final List<DFA> _decisionToDFA = List.generate(
      _ATN.numberOfDecisions, (i) => DFA(_ATN.getDecisionState(i), i));
  static final PredictionContextCache _sharedContextCache = PredictionContextCache();
  static const int TOKEN_WHITESPACE = 1;

  @override
  final List<String> ruleNames = [
    'awal'
  ];

  static final List<String?> _LITERAL_NAMES = [
  ];
  static final List<String?> _SYMBOLIC_NAMES = [
      null, "WHITESPACE"
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

  AwalContext awal() {
    dynamic _localctx = AwalContext(context, state);
    enterRule(_localctx, 0, RULE_awal);
    try {
      enterOuterAlt(_localctx, 1);
      state = 2;
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

  static const List<int> _serializedATN = [
      4,1,1,5,2,0,7,0,1,0,1,0,1,0,0,0,1,0,0,0,3,0,2,1,0,0,0,2,3,5,0,0,1,
      3,1,1,0,0,0,0
  ];

  static final ATN _ATN =
      ATNDeserializer().deserialize(_serializedATN);
}
class AwalContext extends ParserRuleContext {
  TerminalNode? EOF() => getToken(NusantaraLanguageParser.TOKEN_EOF, 0);
  AwalContext([ParserRuleContext? parent, int? invokingState]) : super(parent, invokingState);
  @override
  int get ruleIndex => RULE_awal;
  @override
  void enterRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.enterAwal(this);
  }
  @override
  void exitRule(ParseTreeListener listener) {
    if (listener is NusantaraLanguageParserListener) listener.exitAwal(this);
  }
  @override
  T? accept<T>(ParseTreeVisitor<T> visitor) {
    if (visitor is NusantaraLanguageParserVisitor<T>) {
     return visitor.visitAwal(this);
    } else {
    	return visitor.visitChildren(this);
    }
  }
}

