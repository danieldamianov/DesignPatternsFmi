#pragma once

#include <string>

class TextTransformation
{
public:
	virtual std::string transform(std::string text) const = 0;
};

