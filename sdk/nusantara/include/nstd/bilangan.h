#pragma once

#include <algorithm>
#include <string>

namespace nstd {

    inline std::string toString(const int& nilai) {
        return std::to_string(nilai);
    }

    inline std::string toString(const double& nilai) {
        std::string str = std::to_string(nilai);
        size_t pos = str.find('.');

        // Jika ada koma
        if(pos != std::string::npos) {
            // Hapus angka-angka nol dari belakang desimal
            size_t end = str.find_last_not_of('0');

            // Jika tidak ada digit nol setelah koma
            if(end == pos) {
                str.erase(pos);  // Hapus koma
            } else if(end != std::string::npos && end > pos) {
                str.erase(end + 1);
            }
        }

        // Ganti titik dengan koma
        std::replace(str.begin(), str.end(), '.', ',');
        return str;
    }

}