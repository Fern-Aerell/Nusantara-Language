#pragma once

#define PTR(value) std::unique_ptr<value>
#define PTR_CAST(value, cast_value) const auto* cast_result_ptr = dynamic_cast<cast_value*>(value.get())