import "package:nusantara/nusantara_cli/nusantara_cli.dart";
import "package:nusantara/nusantara_cli/opsi_global.dart";
import "package:nusantara/nusantara_config/config.dart";

void main(List<String> arguments) {

    // Buat opsi global untuk cli
    List<OpsiGlobal> opsiGlobals = [
        OpsiGlobal(
            "info",
            "i",
            "Untuk melihat informasi lebih lanjut.",
            (cli) {
                print("Sebuah alat command-line untuk Nusantara development.");
                print("");
                print("Penggunaan : nusantara <perintah|nlfile> [argumen]");
                print("");
                if(cli.opsiGlobals.isNotEmpty) {
                    print("Opsi global :");
                    for(OpsiGlobal opsiGlobal in cli.opsiGlobals) {
                        String name = "--${opsiGlobal.name}";
                        String alias = "-${opsiGlobal.alias}";
                        String info = opsiGlobal.info;
                        print(" $alias | $name		$info");
                    }
                    print("");
                }
            }
        ),
        OpsiGlobal(
            "versi",
            "v",
            "Untuk melihat versi nusantara.",
            (_) {
                print("$appName $appVersion");
            }
        )
    ];
    
    // Intialize cli
    NusantaraCli cli = NusantaraCli(
        arguments,
        opsiGlobals,
        (cli) {
            cli.opsiGlobals[0].callback(cli);
        },
        (cli) {
            String argument = cli.arguments[0];
            print("Perintah \"$argument\" tidak ada.");
            cli.opsiGlobals[0].callback(cli);
        }
    );
        
    // Eksekusi perintah cli
    cli.execute();
}
