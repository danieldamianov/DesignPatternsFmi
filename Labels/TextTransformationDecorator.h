#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformation.h"

class TextTransformationDecorator : public LabelDecoratorBase
{
private:
	const TextTransformation& textTransformation;

public:
	TextTransformationDecorator(const Label& label, TextTransformation& textTransformation);
	
	std::string getText() const override;
};

