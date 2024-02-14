#pragma once

#include <string>

namespace nstd {

    inline std::string toString(const bool& nilai) {
        return nilai ? "benar" : "salah";
    }

}