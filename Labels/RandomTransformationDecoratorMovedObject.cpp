#include "RandomTransformationDecoratorMovedObject.h"

RandomTransformationDecoratorMovedObject::RandomTransformationDecoratorMovedObject
(std::unique_ptr<Label> label,
	std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
	int(*randomFunction)(int, int))
	: RandomTransformationDecoratorBase(std::move(label), textTranformations, randomFunction)
{ }
