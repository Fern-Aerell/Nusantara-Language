#pragma once

namespace nstd {
    class tipe_data {
        public:
            tipe_data() = default;
            virtual ~tipe_data() = default;
            tipe_data(const tipe_data &) = default;
            tipe_data &operator=(const tipe_data &) = default;
            tipe_data(tipe_data &&) noexcept = default;
            tipe_data &operator=(tipe_data &&) noexcept = default;
    };
}