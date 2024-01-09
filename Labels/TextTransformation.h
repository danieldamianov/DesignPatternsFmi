#pragma once

#include <string>
#include <memory>

class TextTransformation
{
public:
	virtual std::string transform(std::string text) const = 0;
	virtual bool equals(TextTransformation& other) const;
	virtual ~TextTransformation() { }
};

