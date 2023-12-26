#pragma once

#include "Label.h"
#include <memory>

class LabelDecoratorBase : public Label
{
protected: 
	std::shared_ptr<Label> sharedSubject;
	std::unique_ptr<Label> movedSubject;

public:
	LabelDecoratorBase(std::shared_ptr<Label> label);
	LabelDecoratorBase(std::unique_ptr<Label> label);

	virtual std::string getText() const override = 0;
	//// DEBUG PURPOSES
	//~LabelDecoratorBase()
	//{
	//	int a = 5;
	//}
	//// DEBUG PURPOSES
};


