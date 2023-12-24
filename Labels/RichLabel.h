#pragma once
#include "SimpleLabel.h"
#include "Color.h"
#include "Font.h"

class RichLabel : public SimpleLabel
{
private:
	Color color;
	Font font;

public:
	RichLabel(Color color, Font font, std::string text);
	Color getColor();
	Font getFont();
};