import 'package:nusantara/nusantara_interpreter/interpreter_variable.dart';

class InterpreterVariableManager {
	final List<InterpreterVariable> _list = [];
	bool contain(String name) {
		return _list.where((e) => e.name == name).isNotEmpty;
	}
	void create(InterpreterVariable variable) {
		if(contain(variable.name)) {
			throw Exception("Variable ${variable.name} sudah ada.");
		}else{
			_list.add(variable);
		}
	}
	void set(String name, dynamic value) {
		if(contain(name)) {
			InterpreterVariable variable = _list.firstWhere((e) => e.name == name);
			variable.type.setValue(value);
		}else {
			throw Exception("Variable $name belum dibuat.");
		}
	}
	dynamic get(String name) {
		try {
			if(contain(name)) {
					InterpreterVariable variable = _list.firstWhere((e) => e.name == name);
					return variable.type.value;
			}else{
				throw Exception("Variable $name tidak ada.");
			}
		}catch(error) {
			throw Exception("Variable $name belum di isi.");
		}
	}
	void createWithValue(InterpreterVariable variable, dynamic value) {
		create(variable);
		set(variable.name, value);
	}
}
