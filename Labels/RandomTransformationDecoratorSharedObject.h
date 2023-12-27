#pragma once
#include "RandomTransformationDecoratorBase.h"

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

