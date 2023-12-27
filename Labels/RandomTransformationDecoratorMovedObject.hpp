#pragma once
#include "RandomTransformationDecoratorBase.hpp"

template<typename RandomFunctionClassType, typename RandomFunctionType>
class RandomTransformationDecoratorMovedObject 
	: public RandomTransformationDecoratorBase<RandomFunctionClassType, RandomFunctionType>
{
public:
	RandomTransformationDecoratorMovedObject
	(std::unique_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
		RandomFunctionType randomFunction);
};

template <typename RandomFunctionClassType, typename RandomFunctionType>
RandomTransformationDecoratorMovedObject<RandomFunctionClassType, RandomFunctionType>
::RandomTransformationDecoratorMovedObject//<RandomFunctionClassType, RandomFunctionType>
(std::unique_ptr<Label> label,
	std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
	RandomFunctionType randomFunction)
	: RandomTransformationDecoratorBase<RandomFunctionClassType, RandomFunctionType>(std::move(label), textTranformations, randomFunction)
{ }
