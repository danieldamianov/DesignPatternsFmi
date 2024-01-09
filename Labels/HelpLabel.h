#pragma once
#include "SimpleLabel.h"

class HelpLabel : public SimpleLabel
{
private:
	std::string helperText;

public:
	HelpLabel(std::string actualText, std::string helperText);

	std::string getHelperText();
};

