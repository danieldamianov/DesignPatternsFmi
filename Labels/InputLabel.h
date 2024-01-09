#pragma once
#include "Label.h"
#include "RichLabel.h"
#include <istream>

class InputLabel : public Label
{
private:
	const int requestsTimeout = 5;

	// TODO:: FOR NOW;
	mutable RichLabel label;
	mutable int requestsLeft;

	std::istream& stream;

public:
	InputLabel(Color color, Font font, std::istream& stream);

	virtual std::string getText() const override;
};

