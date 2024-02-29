#pragma once

#include "core/format.h"
#include <iostream>

#define PRINT(value) std::cout << value << "\n"
#define PRINTF(value, arg) PRINT(FMT(value, arg))
