#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformation.h"
#include "TextTransformationDecoratorBase.h"

class TextTransformationDecoratorSharedObject : public TextTransformationDecoratorBase
{
public:
	TextTransformationDecoratorSharedObject 
	(std::shared_ptr<Label> label, std::unique_ptr<TextTransformation> textTransformation);

	//// DEBUG PURPOSES
	//~TextTransformationDecoratorSharedObject()
	//{
	//	int a = 5;
	//}
	//// DEBUG PURPOSES
};

