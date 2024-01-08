import 'package:nusantara/nusantara_interpreter/core/data_type.dart';

class BilanganDesimal extends DataType<double> {
  BilanganDesimal(super.value);
  @override
  String toString() {
    return "bilangan desimal";
  }
}