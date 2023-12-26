#include "LabelDecoratorBase.h"

LabelDecoratorBase::LabelDecoratorBase(std::shared_ptr<Label> label)
{
	sharedSubject = label;
	movedSubject = nullptr;
}

LabelDecoratorBase::LabelDecoratorBase(std::unique_ptr<Label> label)
{
	movedSubject = std::move(label);
	sharedSubject = nullptr;
}

