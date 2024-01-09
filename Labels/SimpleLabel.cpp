#include "SimpleLabel.h"
#include "HelpLabel.h"

SimpleLabel::SimpleLabel(std::string text) : helpLabel(text, "no helper text specified for this label")
{
	this->text = text;
}

std::string SimpleLabel::getText() const
{
	return this->text;;
}

void SimpleLabel::setHelperText(std::string helperText)
{
	this->helpLabel.setHelperText(helperText);
}

std::string SimpleLabel::getHelperText()
{
	return this->helpLabel.getHelperText();
}


