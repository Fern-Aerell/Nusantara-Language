#pragma once

#include <memory>

#define PTR(tipe) std::unique_ptr<tipe>
#define MPTR(tipe, value) std::make_unique<tipe>(value)
#define D_CAST(value, tipe) dynamic_cast<tipe*>(value.get())
#define PTR_CAST(value, tipe) auto* cast_result_ptr = D_CAST(value, tipe)
#define SPTR(tipe) std::shared_ptr<tipe>
#define MSPTR(tipe, value) std::make_shared<tipe>(value)
