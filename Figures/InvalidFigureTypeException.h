#pragma once
#include <stdexcept>

class InvalidFigureTypeException : public std::exception
{
public:
	InvalidFigureTypeException(std::string message) : errorMessage(message) {}

	const char* what() const override {
		return errorMessage.c_str();
	}

private:
	std::string errorMessage;
};
