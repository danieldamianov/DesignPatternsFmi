#include "TextTransformationDecoratorSharedObject.h"

TextTransformationDecoratorSharedObject::TextTransformationDecoratorSharedObject
	(std::shared_ptr<Label> label, std::unique_ptr<TextTransformation> textTransformation)
	: TextTransformationDecoratorBase(label, std::move(textTransformation))
{ }
