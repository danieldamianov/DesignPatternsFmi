#pragma once
#include "Label.h"

class SimpleLabel : public Label
{
private:
	std::string text;

	//Helper

public:
	SimpleLabel(std::string text);

	virtual std::string getText() const override;

	
	//// DEBUG PURPOSES
	//~SimpleLabel()
	//{
	//	int a = 5;
	//}
	//// DEBUG PURPOSES
};

