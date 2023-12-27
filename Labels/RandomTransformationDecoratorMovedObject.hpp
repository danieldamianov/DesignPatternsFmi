#pragma once
#include "RandomTransformationDecoratorBase.hpp"

class RandomTransformationDecoratorMovedObject 
	: public RandomTransformationDecoratorBase
{
public:
	RandomTransformationDecoratorMovedObject
	(std::unique_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
		std::weak_ptr<IRandomFunctionProvider> provider);
};

RandomTransformationDecoratorMovedObject
::RandomTransformationDecoratorMovedObject
(std::unique_ptr<Label> label,
	std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
	std::weak_ptr<IRandomFunctionProvider> provider)
	: RandomTransformationDecoratorBase(std::move(label), textTranformations, provider)
{ }
