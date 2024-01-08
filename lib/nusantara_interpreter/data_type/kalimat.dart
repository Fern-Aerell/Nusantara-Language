import 'package:nusantara/nusantara_interpreter/core/data_type.dart';

class Kalimat extends DataType<String> {
  Kalimat(super.value);
  @override
  String toString() {
    return "kalimat";
  }
}