#pragma once
#include "TextTransformation.h"

class CapitalizeTransformation : public TextTransformation
{
	virtual std::string transform(std::string text) const override;
};

