#pragma once
#include "RandomTransformationDecoratorBase.h"

class RandomTransformationDecoratorSharedObject : public RandomTransformationDecoratorBase
{
	RandomTransformationDecoratorSharedObject
	(std::shared_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
		int(*randomFunction)(int, int));
};

