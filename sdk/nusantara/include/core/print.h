#pragma once

#include <iostream>

#include "core/format.h"

#define PRINT(value) std::cout << value << "\n"
#define PRINTF(value, arg) PRINT(FMT(value, arg))
