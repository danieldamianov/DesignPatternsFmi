#pragma once
#include "stdexcept"

class TriangleInequalityException : public std::exception
{
public:
	TriangleInequalityException(std::string message) : errorMessage(message) {}

	const char* what() const override {
		return errorMessage.c_str();
	}

private:
	std::string errorMessage;
};


