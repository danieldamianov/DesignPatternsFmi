#include "RandomTransformationDecoratorSharedObject.h"

RandomTransformationDecoratorSharedObject::RandomTransformationDecoratorSharedObject
(std::shared_ptr<Label> label,
	std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
	int(*randomFunction)(int, int))
	: RandomTransformationDecoratorBase(label, textTranformations, randomFunction)
{ }
