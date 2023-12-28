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

std::shared_ptr<Label> LabelDecoratorBase::removeDecoratorFrom
	(std::shared_ptr<Label> label,
		const type_info* decoratorType,
		std::vector<const type_info*> decoratorTransformations)
{
    if (label == nullptr) {
        return nullptr;
    }
    else if (LabelDecoratorBase.class.isAssignableFrom(label)) {
        // label refers to a decorator. Proceed to remove.
        LabelDecoratorBase ldb = (LabelDecoratorBase)label;
        return ldb.removeDecorator(decoratorType);
    }
    else {
        return label;
    }

}
