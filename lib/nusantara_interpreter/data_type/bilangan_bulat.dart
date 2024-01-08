import 'package:nusantara/nusantara_interpreter/core/data_type.dart';

class BilanganBulat extends DataType<int> {
  BilanganBulat(super.value);
  @override
  String toString() {
    return "bilangan bulat";
  }
}