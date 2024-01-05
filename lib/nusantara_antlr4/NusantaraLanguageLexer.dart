// Generated from /home/aerell/nusantara/grammar/NusantaraLanguageLexer.g4 by ANTLR 4.13.1
// ignore_for_file: unused_import, unused_local_variable, prefer_single_quotes
import 'package:antlr4/antlr4.dart';


class NusantaraLanguageLexer extends Lexer {
  static final checkVersion = () => RuntimeMetaData.checkVersion('4.13.1', RuntimeMetaData.VERSION);

  static final List<DFA> _decisionToDFA = List.generate(
        _ATN.numberOfDecisions, (i) => DFA(_ATN.getDecisionState(i), i));
  static final PredictionContextCache _sharedContextCache = PredictionContextCache();
  static const int
    TOKEN_WHITESPACE = 1;
  @override
  final List<String> channelNames = [
    'DEFAULT_TOKEN_CHANNEL', 'HIDDEN'
  ];

  @override
  final List<String> modeNames = [
    'DEFAULT_MODE'
  ];

  @override
  final List<String> ruleNames = [
    'WHITESPACE'
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


  NusantaraLanguageLexer(CharStream input) : super(input) {
    interpreter = LexerATNSimulator(_ATN, _decisionToDFA, _sharedContextCache, recog: this);
  }

  @override
  List<int> get serializedATN => _serializedATN;

  @override
  String get grammarFileName => 'NusantaraLanguageLexer.g4';

  @override
  ATN getATN() { return _ATN; }

  static const List<int> _serializedATN = [
      4,0,1,10,6,-1,2,0,7,0,1,0,4,0,5,8,0,11,0,12,0,6,1,0,1,0,0,0,1,1,1,
      1,0,1,3,0,9,10,13,13,32,32,10,0,1,1,0,0,0,1,4,1,0,0,0,3,5,7,0,0,0,
      4,3,1,0,0,0,5,6,1,0,0,0,6,4,1,0,0,0,6,7,1,0,0,0,7,8,1,0,0,0,8,9,6,
      0,0,0,9,2,1,0,0,0,2,0,6,1,6,0,0
  ];

  static final ATN _ATN =
      ATNDeserializer().deserialize(_serializedATN);
}