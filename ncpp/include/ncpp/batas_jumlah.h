#pragma once

#include <cstddef>

namespace ncpp {
    struct batas_jumlah_minimal {
        batas_jumlah_minimal() = default;
        explicit batas_jumlah_minimal(const size_t& jumlah);
        size_t jumlah = 0;
        bool batasan = false;
        bool operator==(const batas_jumlah_minimal& other) const;
        bool operator!=(const batas_jumlah_minimal& other) const;
    };
    struct batas_jumlah_maksimal {
        batas_jumlah_maksimal() = default;
        explicit batas_jumlah_maksimal(const size_t& jumlah);
        size_t jumlah = 0;
        bool batasan = false;
        bool operator==(const batas_jumlah_maksimal& other) const;
        bool operator!=(const batas_jumlah_maksimal& other) const;
    };
    struct batas_jumlah {
        batas_jumlah() = default;
        explicit batas_jumlah(const size_t& min, const size_t& max);
        explicit batas_jumlah(const batas_jumlah_minimal& min);
        explicit batas_jumlah(const batas_jumlah_maksimal& max);
        batas_jumlah_minimal min;
        batas_jumlah_maksimal max;
        bool operator==(const batas_jumlah& other) const;
        bool operator!=(const batas_jumlah& other) const;
    };
}