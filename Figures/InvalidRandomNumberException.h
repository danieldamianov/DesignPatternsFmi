#pragma once
#include <stdexcept>

class InvalidRandomNumberException : public std::exception
{
public:
    InvalidRandomNumberException(std::string message) : errorMessage(message) { }

    const char* what() const override {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

