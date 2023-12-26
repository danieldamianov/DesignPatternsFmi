#pragma once
#include "TextTransformation.h"

class CapitalizeTransformation : public TextTransformation
{
	virtual std::string transform(std::string text) const override;

//	// DEBUG PURPOSES
//public:
//	~CapitalizeTransformation()
//	{
//		int a = 5;
//	}
//	// DEBUG PURPOSES
};

