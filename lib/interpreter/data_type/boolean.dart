import '../core/data_type.dart';
import '../nilai/nilai_boolean.dart';

class Boolean extends DataType<NilaiBoolean> {
  Boolean(super.value);
  @override
  String toString() {
    return "boolean";
  }
}