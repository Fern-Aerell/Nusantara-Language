import '../core/data_type.dart';

class Karakter extends DataType<String> {
  Karakter(super.value);

  @override
  void setValue(String value) {
    if(value.isEmpty || value.length == 1) {
      setValue(value);
    }else{
      throw Exception("'$value' bukan lah sebuah karakter");
    }
  }
  @override
  String toString() {
    return "karakter";
  }
}