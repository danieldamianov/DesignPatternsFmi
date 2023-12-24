#pragma once
#include "Label.h"

class SimpleLabel : public Label
{
private:
	std::string text;

public:
	SimpleLabel(std::string text);

	virtual std::string getText() const override;
};

