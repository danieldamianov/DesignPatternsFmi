#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformation.h"
#include "vector"

class RandomTransformationDecoratorBase : public LabelDecoratorBase
{
private:
	std::vector<std::unique_ptr<TextTransformation>> transformations;
	int (*randomFunction)(int, int);

	void initializeTransformations
	(std::vector<std::unique_ptr<TextTransformation>>& transformations);

protected:
	RandomTransformationDecoratorBase(std::shared_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
		int (*randomFunction)(int, int));

	RandomTransformationDecoratorBase(std::unique_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
		int (*randomFunction)(int, int));

	virtual std::string getText() const override;
};