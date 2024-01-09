#include "HelpLabel.h"

HelpLabel::HelpLabel(std::string actualText, std::string helperText)
	: SimpleLabel(actualText), helperText(helperText)
{ }

std::string HelpLabel::getHelperText()
{
	return this->helperText;
}
