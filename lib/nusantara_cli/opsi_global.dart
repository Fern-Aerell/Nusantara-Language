import "nusantara_cli.dart";

class OpsiGlobal {
    final String name;
    final String alias;
    final String info;
    final Function(NusantaraCli cli) callback;
    OpsiGlobal(this.name, this.alias, this.info, this.callback);
}