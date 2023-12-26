#include "TextTransformationDecoratorBase.h"

TextTransformationDecoratorBase::TextTransformationDecoratorBase
	(std::shared_ptr<Label> label, std::unique_ptr<TextTransformation> textTransformation)
	: LabelDecoratorBase(label), textTransformation(std::move(textTransformation))
{
}

TextTransformationDecoratorBase::TextTransformationDecoratorBase
(std::unique_ptr<Label> label, std::unique_ptr<TextTransformation> textTransformation)
	: LabelDecoratorBase(std::move(label)), textTransformation(std::move(textTransformation))
{ }

std::string TextTransformationDecoratorBase::getText() const
{
	std::string str = this->sharedSubject != nullptr ? 
		this->sharedSubject->getText() : 
		this->movedSubject->getText();

	str = this->textTransformation->transform(str);
	return str;
}
