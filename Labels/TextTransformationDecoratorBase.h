#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformation.h"

class TextTransformationDecoratorBase : public LabelDecoratorBase
{
private: 
	std::unique_ptr<TextTransformation> textTransformation;

protected:
	TextTransformationDecoratorBase(std::shared_ptr<Label> label,
		std::unique_ptr<TextTransformation> textTransformation);
	TextTransformationDecoratorBase(std::unique_ptr<Label> label,
		std::unique_ptr<TextTransformation> textTransformation);

public:

	virtual std::string getText() const override;
	
	virtual std::vector<const type_info*> getTransformationTypes() override;

	virtual bool equals(LabelDecoratorBase& other) override;

	// DEBUG PURPOSES
	~TextTransformationDecoratorBase()
	{
		int a = 5;
	}
	// DEBUG PURPOSES
};
