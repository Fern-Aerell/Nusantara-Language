import 'package:nusantara/nusantara_interpreter/core/data_type.dart';
import 'package:nusantara/nusantara_interpreter/nilai/nilai_boolean.dart';

class Boolean extends DataType<NilaiBoolean> {
  Boolean(super.value);
  @override
  String toString() {
    return "boolean";
  }
}