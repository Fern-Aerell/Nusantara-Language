class DataType<T> implements Type {
  T? _value;
  DataType(this._value);
  T? get value => _value;
  void setValue(T value) => _value = value;
}