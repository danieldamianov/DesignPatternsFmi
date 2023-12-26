#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformation.h"
#include "TextTransformationDecoratorBase.h"

class TextTransformationDecoratorMovedObject : public TextTransformationDecoratorBase
{
public:
	TextTransformationDecoratorMovedObject
	(std::unique_ptr<Label> label, std::unique_ptr<TextTransformation> textTransformation);
};

