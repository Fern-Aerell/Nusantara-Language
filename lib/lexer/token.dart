class Token {
  final String source;
  final int line;
  final int startPositionInLine;
  final int endPositionInLine;
  final Enum type;
  final String content;

  Token({required this.source, required this.line, required this.startPositionInLine, required this.endPositionInLine, required this.type, required this.content});

  @override
  String toString() {
    return "$source:$line:${"$startPositionInLine".padRight(5)} => ${"$type".padRight(20)} '$content'";
  }
}