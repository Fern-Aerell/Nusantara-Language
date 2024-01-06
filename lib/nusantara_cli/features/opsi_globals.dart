import '../nusantara_cli.dart';
import 'cli_feature.dart';
import 'opsi_global.dart';

class OpsiGlobals extends CliFeature {

  final List<OpsiGlobal> list;
  late final String _argument;

  OpsiGlobals(this.list);

  @override
  void implements(NusantaraCli cli) {
    super.implements(cli);
    if(cli.arguments.isNotEmpty && cli.arguments.length == 1) {
      _argument = cli.arguments[0];
      for(OpsiGlobal opsiGlobal in list) {
        String name = "--${opsiGlobal.name}";
        String alias = "-${opsiGlobal.alias}";
        if(_argument == name || _argument == alias) {
          opsiGlobal.callback(list);
          execute();
        }
      }
    }
  }
}