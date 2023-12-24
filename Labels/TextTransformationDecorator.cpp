#include "TextTransformationDecorator.h"

TextTransformationDecorator::TextTransformationDecorator(const Label& label, TextTransformation& textTransformation)
	: LabelDecoratorBase(label), textTransformation(textTransformation)
{ }

std::string TextTransformationDecorator::getText() const
{
	std::string str = this->subject.getText();
	str = this->textTransformation.transform(str);
	return str;
}
