#pragma once

#include <map>
#include <sstream>
#include <string>

namespace nstd {

    template<class Key, class Value>
    using peta = std::map<Key, Value>;

    template<class Key, class Value>
    inline std::string toString(const peta<Key, Value>& peta) {
        std::ostringstream stream;
        int index = 0;
        for(const auto &pair : peta) {
        if(index == 0) {
            stream << "["
                << "\n";
        }
        stream << " [" << pair.first << "]=" << pair.second;
        if(index < (peta.size() - 1)) {
            stream << ","
                << "\n";
        } else {
            stream << "\n"
                << "]";
        }
        ++index;
        }
        return stream.str();
    }
}