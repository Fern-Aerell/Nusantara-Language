import 'package:nusantara/nusantara_interpreter/core/data_type.dart';
import 'package:nusantara/nusantara_interpreter/utils/utils.dart';

class Variable {
  final String name;
  final DataType type;
  Variable(this.name, this.type);
  dynamic get value => type.value;
  @override
  Type get runtimeType => type;
  @override
  String toString() {
    return "$value";
  }
  void set(dynamic value) {
    if(type.value.runtimeType == value.runtimeType) {
      type.setValue(value);
    }else {
      throw Exception("Tipe '${dynamicRuntimeType(value)}' bukan subtipe dari tipe '$type' dari '$name'");
    }
  }
}