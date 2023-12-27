#pragma once
#include "RandomTransformationDecoratorBase.hpp"

template <typename RandomFunctionClassType, typename RandomFunctionType>
class RandomTransformationDecoratorSharedObject 
	: public RandomTransformationDecoratorBase<RandomFunctionClassType, RandomFunctionType>
{
public:
	RandomTransformationDecoratorSharedObject
	(std::shared_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTransformations,
		RandomFunctionType randomFunction);
};

template<typename RandomFunctionClassType, typename RandomFunctionType>
RandomTransformationDecoratorSharedObject<RandomFunctionClassType, RandomFunctionType>
::RandomTransformationDecoratorSharedObject<RandomFunctionClassType, RandomFunctionType>
(std::shared_ptr<Label> label,
	std::vector<std::unique_ptr<TextTransformation>>& textTransformations,
	RandomFunctionType randomFunction)
	: RandomTransformationDecoratorBase<RandomFunctionClassType, RandomFunctionType>(label, textTransformations, randomFunction)
{ }

