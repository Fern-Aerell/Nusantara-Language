import '../data_type/bilangan_bulat.dart';
import '../data_type/bilangan_desimal.dart';
import '../data_type/boolean.dart';
import '../data_type/kalimat.dart';
import '../data_type/karakter.dart';

String dynamicRuntimeType(dynamic value) {
  if(value.runtimeType == int) {
    return "${BilanganBulat(null)}";
  }else if(value.runtimeType == double) {
    return "${BilanganDesimal(null)}";
  }else if(value.runtimeType == String && (value as String).isEmpty || (value as String).length == 1) {
    return "${Karakter(null)}";
  }else if(value.runtimeType == String) {
    return "${Kalimat(null)}";
  }else if(value.runtimeType == bool) {
    return "${Boolean(null)}";
  }else{
    return "${value.runtimeType}";
  }
}