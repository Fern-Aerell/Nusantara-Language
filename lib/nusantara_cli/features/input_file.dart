import 'dart:io';
import '../nusantara_cli.dart';
import 'cli_feature.dart';

class InputFile extends CliFeature {
  late final File _file;
  final String extension;
  final Function(File file) callback;
  InputFile(this.extension, this.callback);

  @override
  void implements(NusantaraCli cli) {
    super.implements(cli);
    if(cli.arguments.isNotEmpty && cli.arguments.length == 1 && cli.arguments.first.endsWith(extension)) {
      _file = File(cli.arguments.first);
      execute();
    }
  }

  @override
  void execute() {
    super.execute();
    callback(_file);
  }
}