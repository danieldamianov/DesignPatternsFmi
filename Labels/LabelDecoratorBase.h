#pragma once

#include "Label.h"
#include <memory>
#include <vector>

class LabelDecoratorBase : public Label
{
private:
	static std::unique_ptr<Label> removeDecoratorFromRecursive
	(std::unique_ptr<LabelDecoratorBase> label,
		std::unique_ptr<LabelDecoratorBase> decoratorToRemove);
protected: 
	std::shared_ptr<Label> sharedSubject;
	std::unique_ptr<Label> movedSubject;

public:
	LabelDecoratorBase(std::shared_ptr<Label> label);
	LabelDecoratorBase(std::unique_ptr<Label> label);

	virtual std::string getText() const override = 0;

	virtual std::vector<const type_info*> getTransformationTypes() = 0;

	virtual bool equals(LabelDecoratorBase& other) = 0;

	static std::unique_ptr<Label> removeDecoratorFrom
	(std::unique_ptr<Label> label,
		std::unique_ptr<LabelDecoratorBase> decoratorToRemove);

	// TODO:: THink carefully about the sharedPointers!

	//// DEBUG PURPOSES
	//~LabelDecoratorBase()
	//{
	//	int a = 5;
	//}
	//// DEBUG PURPOSES
};


