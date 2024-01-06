import "features/cli_feature.dart";

class NusantaraCli {

  final List<String> arguments;
  final List<CliFeature> features;

  NusantaraCli(this.arguments, this.features) {
    for (CliFeature feature in features) {
      if(features.where((element) => element.runtimeType == feature.runtimeType).length > 1) throw Exception("Terdapat dua atau lebih fitur cli \"${feature.runtimeType}\".");
    }
  }

  void execute() {
    for (CliFeature feature in features) {
      feature.implements(this);
    }
  }

}
