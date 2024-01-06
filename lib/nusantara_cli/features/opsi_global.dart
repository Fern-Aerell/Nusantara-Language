class OpsiGlobal {
    final String name;
    final String alias;
    final String info;
    final Function(List<OpsiGlobal> opsiGlobals) callback;
    OpsiGlobal(this.name, this.alias, this.info, this.callback);
}