#pragma once

#define STD std::
#define NSTD nstd::
#define ND [[nodiscard]]

#define CLASS_DECLARE_OPERATION_LEFT_RIGHT(result, op, with_type) result operator op (const with_type& nilaiX)
#define CLASS_DECLARE_OPERATION_LEFT_RIGHT_CONST(result, op, with_type) CLASS_DECLARE_OPERATION_LEFT_RIGHT(result, op, with_type) const
#define CLASS_DEFINE_OPERATION_LEFT_RIGHT(class_name, result, op, with_type, code) result class_name ::operator op (const with_type& nilaiX) {code}
#define CLASS_DEFINE_OPERATION_LEFT_RIGHT_CONST(class_name, result, op, with_type, code) result class_name ::operator op (const with_type& nilaiX) const {code}
