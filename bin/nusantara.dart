import "package:nusantara/nusantara_cli/features/argument_empty_callback.dart";
import "package:nusantara/nusantara_cli/features/argument_invalid_callback.dart";
import "package:nusantara/nusantara_cli/features/cli_feature.dart";
import "package:nusantara/nusantara_cli/features/input_file.dart";
import "package:nusantara/nusantara_cli/features/opsi_globals.dart";
import "package:nusantara/nusantara_cli/nusantara_cli.dart";
import 'package:nusantara/nusantara_cli/features/opsi_global.dart';
import "package:nusantara/nusantara_config/config.dart";
import "package:nusantara/nusantara_intepreter/intepreter.dart";

void main(List<String> arguments) {

  // Cli feature
  List<CliFeature> features = [
    InputFile(nusantaraLanguageFileExtension, (file) async {
      if(file.existsSync()) {
        Intepreter(file);
      }else{
        print("File \"${file.path}\" tidak ada.");
      }
    }),
    OpsiGlobals(
      [
        OpsiGlobal("versi", "v", "Untuk melihat versi nusantara.", (_) {
          print("$appName $appVersion");
        }),
        OpsiGlobal("info", "i", "Untuk melihat informasi lebih lanjut.", (list) {
          print("Sebuah alat command-line untuk Nusantara development.");
          print("");
          print("Penggunaan : nusantara <perintah|nlfile> [argumen]");
          print("");
          if(list.isNotEmpty) {
            for(OpsiGlobal opsiGlobal in list) {
              String name = "--${opsiGlobal.name}";
              String alias = "-${opsiGlobal.alias}";
              String info = opsiGlobal.info;
              print(" $alias | $name    $info");
            }
            print("");
          }
        })
      ]
    ),
    ArgumentEmptyCallback((arguments, features) {
      List<OpsiGlobal> opsiGlobal = (features.firstWhere((element) => element.runtimeType == OpsiGlobals) as OpsiGlobals).list;
      opsiGlobal.firstWhere((element) => element.name == "info").callback(opsiGlobal);
    },),
    ArgumentInvalidCallback((argument, features) {
      print("Perintah \"$argument\" tidak ada.");
      (features.firstWhere((element) => element.runtimeType == ArgumentEmptyCallback)).execute();
    },)
  ];

  // Intialize cli
  NusantaraCli cli = NusantaraCli(arguments, features);

  // Eksekusi perintah cli
  cli.execute();
}
