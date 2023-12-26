#pragma once
#include "RandomTransformationDecoratorBase.h"

class RandomTransformationDecoratorMovedObject : public RandomTransformationDecoratorBase
{
	RandomTransformationDecoratorMovedObject
	(std::unique_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
		int(*randomFunction)(int, int));
};

