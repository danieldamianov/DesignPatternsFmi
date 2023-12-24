#include "SimpleLabel.h"

SimpleLabel::SimpleLabel(std::string text)
{
	this->text = text;
}

std::string SimpleLabel::getText() const
{
	return this->text;;
}
