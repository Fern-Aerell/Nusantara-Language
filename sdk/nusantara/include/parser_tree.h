#pragma once

#include "token.h"
#include <memory>
#include <string>
#include <vector>

class ParserTree {
    public:
        ParserTree() = default;
        virtual ~ParserTree() = default;                        // destructor (virtual if X is meant to be a base class)
        ParserTree(const ParserTree&) = default;                // copy constructor
        ParserTree& operator=(const ParserTree&) = default;     // copy assignment
        ParserTree(ParserTree&&) noexcept = default;            // move constructor
        ParserTree& operator=(ParserTree&&) noexcept = default; // move assignment
        virtual std::string toString() = 0;
        void printTree(const int& indent);
        void addChild(std::unique_ptr<ParserTree> child);
    private:
        std::vector<std::unique_ptr<ParserTree>> children;
};

class ParserRuleTree: public ParserTree {
    public:
        explicit ParserRuleTree(std::string name);
        std::string toString() override;
    private:
        std::string name;
};

class ParserTokenTree: public ParserTree {
    public:
        explicit ParserTokenTree(Token token);
        std::string toString() override;
    private:
        Token token;
};