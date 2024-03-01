#pragma once

#define STD std::
#define NSTD nstd::
#define ND [[nodiscard]]

#define CLASS_DECLARE_OPERATION_LEFT_RIGHT(result, op, with_type) result operator op (const with_type& nilaiX) const
