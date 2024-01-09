#include "HelpLabel.h"

HelpLabel::HelpLabel(std::string actualText, std::string helperText)
	: actualText(actualText), helperText(helperText)
{ }

std::string HelpLabel::getHelperText()
{
	return this->helperText;
}

std::string HelpLabel::getText() const
{
	return this->actualText;
}

void HelpLabel::setHelperText(std::string helperText)
{
	this->helperText = helperText;
}

