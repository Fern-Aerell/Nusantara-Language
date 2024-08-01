#pragma once

#include <string>
#include <vector>

class NCli {

    private:
        std::vector<std::string> arguments;

    public:
        NCli(const int& argc, const char**& argv);
        
};