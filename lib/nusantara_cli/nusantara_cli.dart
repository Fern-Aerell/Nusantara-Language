import "opsi_global.dart";

class NusantaraCli {

	final List<String> arguments;
    final List<OpsiGlobal> opsiGlobals;
    final Function(NusantaraCli cli)? argumentEmptyCallback;
    final Function(NusantaraCli cli)? argumentInvalidCallback;
    
    NusantaraCli(this.arguments, this.opsiGlobals, this.argumentEmptyCallback, this.argumentInvalidCallback);

	void execute() {
        if(arguments.isEmpty) {
            if(argumentEmptyCallback != null) argumentEmptyCallback!(this);
            return;
        }
        
        if(arguments.length == 1) {
            String argument = arguments[0];
            // opsi global
            for(OpsiGlobal opsiGlobal in opsiGlobals) {
                String name = "--${opsiGlobal.name}";
                String alias = "-${opsiGlobal.alias}";
                if(argument == name || argument == alias) {
                    opsiGlobal.callback(this);
                    return;
                }
            }
        }
        
        if(argumentInvalidCallback != null) argumentInvalidCallback!(this);
    }
}
