#pragma once
#include "TextTransformation.h"

class LeftTrimTransformation : public TextTransformation
{
    virtual std::string transform(std::string text) const override;

	// DEBUG PURPOSES
public:
	~LeftTrimTransformation()
	{
		int a = 5;
	}
	// DEBUG PURPOSES
};

