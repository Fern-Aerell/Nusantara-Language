#pragma once

#include <iostream>
#include "core/format.h"

#define PRINT(value) std::cout << value << "\n"
#define PRINTF(value, args) PRINT(FMT(value, args))
