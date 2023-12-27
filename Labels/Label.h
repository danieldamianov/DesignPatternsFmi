#pragma once
#include <string>

// TODO:: CHange to ILabel for consistency
class Label
{
public:
	virtual std::string getText() const = 0;
	virtual ~Label() { }
};

