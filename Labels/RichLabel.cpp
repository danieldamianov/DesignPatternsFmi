#include "RichLabel.h"

RichLabel::RichLabel(Color color, Font font, std::string text) : SimpleLabel(text)
{
	this->color = color;
	this->font = font;
}

Color RichLabel::getColor()
{
	return this->color;
}

Font RichLabel::getFont()
{
	return this->font;
}
