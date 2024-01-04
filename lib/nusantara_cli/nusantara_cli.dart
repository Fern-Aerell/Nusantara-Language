import "package:args/args.dart";
import "package:nusantara/nusantara_config/config.dart";

class NusantaraCli {
	final List<String> arguments;
	late final int argumentsLength;
	final ArgParser argParser = ArgParser();
	bool _infoFlag = false;
	bool _versiFlag = false;
	NusantaraCli(this.arguments) {
		// Simpan panjang argumen
		argumentsLength = arguments.length;
		// Flag versi
		argParser.addFlag(
			"versi", 
			abbr: "v", 
			help: "Untuk melihat versi nusantara."
		);
		// Flag info
		argParser.addFlag(
			"info",
			abbr: "i", 
			help: "Untuk melihat informasi lebih lanjut."
		);
	}

	void _info() {
		print("Sebuah alat command-line untuk Nusantara development.");
		print("");
		print("Cara penggunaan : nusantara <perintah|nlfile|nsfile> [argumen]");
		print("");
		print("Opsi umum : ");
		print("	-v | --versi 		${argParser.options["versi"]?.help}");
		print("	-i | --info 		${argParser.options["info"]?.help}");
	}

	void _versi() {
		print("$appName $appVersion");
	}

	void execute() {
		ArgResults argResult = argParser.parse(arguments);
		_infoFlag = argResult["info"];
		_versiFlag = argResult["versi"];
		if(_infoFlag && !_versiFlag) {
			_info();
		}else if(_versiFlag && !_infoFlag) {
			_versi();
		}
	}
}
