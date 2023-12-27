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

std::unique_ptr<Label> LabelDecoratorBase::removeDecoratorFrom
	(std::shared_ptr<Label> label,
		std::type_info decoratorType,
		std::vector<const std::type_info&> decoratorTransformations)
{
	return std::unique_ptr<Label>();
}
