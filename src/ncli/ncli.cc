#include <iostream>
#include <span>

#include "ncli/ncli.hh"
#include "configs/app.hh"

NCli::NCli(const int& argc, const char**& argv) {

    std::cout << "Program now running with Nusantara command-line interface..." << "\n\n";

    auto args = std::span(argv, size_t(argc));

    for(size_t i = 0; i < size_t(argc); ++i) {
        this->arguments.emplace_back(args[i]);
    }

    std::cout << "Name: " << PROGRAM_NAME << "\n";
    std::cout << "Version: " << PROGRAM_VERSION << "\n";
    std::cout << "Creator: " << PROGRAM_CREATOR << "\n\n";

    std::cout << "Argument Count: " << this->arguments.size() << "\n";
    if(this->arguments.size() > 0) {
        std::cout << "Arguments:\n";
        for(const auto& argument : this->arguments) {
            std::cout << " - " << argument << "\n";
        }
    }

    std::cout << "\n";
}