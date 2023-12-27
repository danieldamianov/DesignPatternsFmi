#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformation.h"
#include "vector"

template <typename RandomFunctionClassType ,typename RandomFunctionType>
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
		RandomFunctionType randomFunction);

	RandomTransformationDecoratorBase(std::unique_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
		RandomFunctionType randomFunction);

	virtual std::string getText() const override;
};