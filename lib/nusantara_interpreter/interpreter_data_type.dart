abstract class InterpreterDataType<T> {
	late T _value;
	T get value => _value;
	void setValue(T value) {
		_value = value;
	}
}
