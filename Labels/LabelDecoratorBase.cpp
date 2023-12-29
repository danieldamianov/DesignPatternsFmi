#include "LabelDecoratorBase.h"

std::unique_ptr<Label> LabelDecoratorBase::removeDecoratorFromRecursive(std::unique_ptr<LabelDecoratorBase> label, std::unique_ptr<LabelDecoratorBase> decoratorToRemove)
{
    if (label->equals(*decoratorToRemove))
    {
        // TODO:: THIS IS WRONG! THINK AGAIN HOW TO FIX IT;
        // FOR NOW, I WANT TOW SEE JUST A SKELETON
        return std::move(label->movedSubject);
    }
    else if (LabelDecoratorBase* subjectConverted = dynamic_cast<LabelDecoratorBase*>(label->movedSubject.release()))
    {
        // The subject is itself a decorator.
        // Try to remove decoratorType from it.
        // Note that we may need to reassign subject, because the
        // requested decorator may be on top of the list.
        label->movedSubject = LabelDecoratorBase
            ::removeDecoratorFromRecursive(std::unique_ptr<LabelDecoratorBase>(subjectConverted), std::move(decoratorToRemove));
    
        // Return the current object to keep it on top of the list
        // ALMOST SURELY DOESN'T WORK
        return std::move(label);
    }
    else {
        // The subject is not a decorator.
        // We have reached the end of the list and have not found decoratorType.
        // We can either throw an exception here,
        // or do nothing and simply return the current object.
    
        // THINK AGAIN LATER !!!!!!!!!!!! WRONG INPLEMENTATION!!!
        //throw 10;
        return std::move(label);
    }
}

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

std::unique_ptr<Label> LabelDecoratorBase::removeDecoratorFrom(std::unique_ptr<Label> label, std::unique_ptr<LabelDecoratorBase> decoratorToRemove)
{
	if (label == nullptr) {
		return nullptr;
	}
	else if (LabelDecoratorBase* decorator = dynamic_cast<LabelDecoratorBase*>(label.release()))
	{
		// label refers to a decorator. Proceed to remove.
		return removeDecoratorFromRecursive
        (std::unique_ptr<LabelDecoratorBase>(decorator), std::move(decoratorToRemove));
	}
	else {
		return std::move(label);
	}
}