#include "TextTransformationDecoratorMovedObject.h"
#include "TextTransformationDecoratorBase.h"

TextTransformationDecoratorMovedObject::TextTransformationDecoratorMovedObject
	(std::unique_ptr<Label> label, std::unique_ptr<TextTransformation> textTransformation) :
	TextTransformationDecoratorBase(std::move(label), std::move(textTransformation))
{ }
