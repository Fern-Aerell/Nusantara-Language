import '../nusantara_cli.dart';
import 'cli_feature.dart';

class ArgumentInvalidCallback extends CliFeature {
  late final String _argument;
  late final List<CliFeature> _features;
  final Function(String argument, List<CliFeature> features) callback;

  ArgumentInvalidCallback(this.callback);

  @override
  void implements(NusantaraCli cli) {
    super.implements(cli);
    if(cli.arguments.isNotEmpty) {
      _argument = cli.arguments[0];
      _features = cli.features;
      if(_features.where((element) => element.isExecute == true).isEmpty) {
        execute();
      }
    }
  }

  @override
  void execute() {
    super.execute();
    callback(_argument, _features);
  }
}