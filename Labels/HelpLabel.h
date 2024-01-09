#pragma once
#include "Label.h"

class HelpLabel : public Label
{
private:
	std::string helperText;
	std::string actualText;

public:
	HelpLabel(std::string actualText, std::string helperText);

	virtual std::string getHelperText() override;
	virtual std::string getText() const override;
	virtual void setHelperText(std::string helperText) override;
};

