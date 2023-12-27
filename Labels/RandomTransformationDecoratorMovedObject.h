#pragma once
#include "RandomTransformationDecoratorBase.h"

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

