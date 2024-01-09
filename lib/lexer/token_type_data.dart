class TokenTypeData {
  late final Enum enumTokenType;
  late final RegExp rule;
  late final bool skip;
  TokenTypeData({required this.enumTokenType, required this.rule, this.skip = false});
  @override
  String toString() {
    return enumTokenType.name;
  }
  Map<String, dynamic> toJson() {
    Map<String, dynamic> dataMap = {};
    // Name
    dataMap["name"] = enumTokenType.name;
    // Rule
    Map<String, dynamic> ruleMap = {};
    ruleMap["pattern"] = rule.pattern;
    ruleMap["case_sensitive"] = rule.isCaseSensitive;
    ruleMap["dot_all"] = rule.isDotAll;
    ruleMap["multiline"] = rule.isMultiLine;
    ruleMap["unicode"] = rule.isUnicode;
    dataMap["rule"] = ruleMap;
    // Skip
    dataMap["skip"] = skip;
    return dataMap;
  }
  TokenTypeData.fromJson(Map<String, dynamic> data, Enum Function(String name) stringToEnum) {
    enumTokenType = stringToEnum(data["name"]);
    Map<String, dynamic> ruleData = data["rule"];
    rule = RegExp(ruleData["pattern"], dotAll: ruleData["dot_all"], multiLine: ruleData["multiline"], unicode: ruleData["unicode"], caseSensitive: ruleData["case_sensitive"]);
    skip = data["skip"];
  }
}