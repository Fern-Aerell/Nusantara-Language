import '../cli.dart';

abstract class CliFeature {
  bool _isImplements = false;
  bool _isExecute = false;

  bool get isImplements => _isImplements;
  bool get isExecute => _isExecute;

  void implements(Cli cli) {
    _isImplements = true;
  }

  void execute() {
    if(!_isImplements) throw Exception("Fitur cli \"$runtimeType\" ini belum di implementasikan.");
    _isExecute = true;
  }
}