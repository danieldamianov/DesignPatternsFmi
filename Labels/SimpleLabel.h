#pragma once
#include "Label.h"
#include "HelpLabel.h"
#include <memory>

class HelpLabel;

class SimpleLabel : public Label
{
private:
	std::string text;
	HelpLabel helpLabel;

public:
	SimpleLabel(std::string text);

	virtual std::string getText() const override;
	virtual void setHelperText(std::string helperText) override;
    virtual std::string getHelperText() override;


	
	//// DEBUG PURPOSES
	//~SimpleLabel()
	//{
	//	int a = 5;
	//}
	//// DEBUG PURPOSES
};

