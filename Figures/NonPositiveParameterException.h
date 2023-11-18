#pragma once
#include "stdexcept"

class NonPositiveParameterException : public std::exception
{
public:
	NonPositiveParameterException(std::string message) : errorMessage(message) {}

	const char* what() const override {
		return errorMessage.c_str();
	}

private:
	std::string errorMessage;
};


