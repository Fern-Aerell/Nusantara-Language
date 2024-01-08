import 'package:nusantara/nusantara_interpreter/core/data_type.dart';

import 'variable.dart';

class VariableManager {
  final List<Variable> _variables = [];
  void create(String name, DataType type) {
    if(!alreadyCreated(name)) {
      _variables.add(Variable(name, type));
    }else{
      throw Exception("Variable $name sudah ada");
    }
  }
  bool alreadyCreated(String name) {
    return _variables.where((element) => element.name == name).isNotEmpty;
  }
  void set(String name, dynamic value) {
    Variable variable = get(name);
    variable.set(value);
  }
  Variable get(String name) {
    if(alreadyCreated(name)) {
      return _variables.firstWhere((element) => element.name == name);
    }else{
      throw Exception("Variable $name belum ada");
    }
  }
  dynamic getValue(String name) {
    return get(name).value;
  }
}