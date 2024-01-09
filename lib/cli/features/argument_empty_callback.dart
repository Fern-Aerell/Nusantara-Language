import '../cli.dart';
import 'cli_feature.dart';

class ArgumentEmptyCallback extends CliFeature {

  late final List<String> _arguments;
  late final List<CliFeature> _features;
  final Function(List<String> arguments, List<CliFeature> features) callback;

  ArgumentEmptyCallback(this.callback);

  @override
  void implements(Cli cli) {
    super.implements(cli);
    _arguments = cli.arguments;
    _features = cli.features;
    if(_arguments.isEmpty) execute();
  }

  @override
  void execute() {
    super.execute();
    callback(_arguments, _features);
  }

}