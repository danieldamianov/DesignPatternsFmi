#pragma once

#include "Label.h"

class LabelDecoratorBase : public Label
{
protected: 
	const Label& subject;

public:
	LabelDecoratorBase(const Label& label);
	virtual std::string getText() const override;
};


