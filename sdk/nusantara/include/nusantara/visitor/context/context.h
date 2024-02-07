#pragma once

class Context {
    public:
        Context() = default; // constructor
        virtual ~Context() = default;                     // destructor (virtual if X is meant to be a base class)
        Context(const Context&) = default;                // copy constructor
        Context& operator=(const Context&) = default;     // copy assignment
        Context(Context&&) noexcept = default;            // move constructor
        Context& operator=(Context&&) noexcept = default; // move assignment
    private:
};