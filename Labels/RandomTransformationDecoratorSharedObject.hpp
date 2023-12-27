#pragma once
#include "RandomTransformationDecoratorBase.hpp"

class RandomTransformationDecoratorSharedObject 
	: public RandomTransformationDecoratorBase
{
public:
	RandomTransformationDecoratorSharedObject
	(std::shared_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTransformations,
		std::weak_ptr<IRandomFunctionProvider> provider);
};

RandomTransformationDecoratorSharedObject
::RandomTransformationDecoratorSharedObject
(std::shared_ptr<Label> label,
	std::vector<std::unique_ptr<TextTransformation>>& textTransformations,
	std::weak_ptr<IRandomFunctionProvider> provider)
	: RandomTransformationDecoratorBase(label, textTransformations, provider)
{ }

