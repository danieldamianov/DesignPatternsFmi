#pragma once

#include "Label.h"
#include <memory>
#include <vector>

class LabelDecoratorBase : public Label
{
protected: 
	std::shared_ptr<Label> sharedSubject;
	std::unique_ptr<Label> movedSubject;

public:
	LabelDecoratorBase(std::shared_ptr<Label> label);
	LabelDecoratorBase(std::unique_ptr<Label> label);

	virtual std::string getText() const override = 0;

	virtual std::vector<const type_info*> getTransformationTypes() = 0;

	static std::shared_ptr<Label> removeDecoratorFrom
		(std::shared_ptr<Label> label,
			const type_info* decoratorType,
			std::vector<const type_info*> decoratorTransformations);

	virtual bool equals(const std::unique_ptr<LabelDecoratorBase> other) = 0;
	//// DEBUG PURPOSES
	//~LabelDecoratorBase()
	//{
	//	int a = 5;
	//}
	//// DEBUG PURPOSES
};


