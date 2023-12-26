#include "RandomTransformationDecoratorBase.h"

void RandomTransformationDecoratorBase::initializeTransformations
(std::vector<std::unique_ptr<TextTransformation>>& transformations)
{
	for (int i = 0; i < transformations.size(); i++)
	{
		this->transformations.push_back(std::move(transformations[i]));
	}
}

RandomTransformationDecoratorBase::RandomTransformationDecoratorBase
(std::shared_ptr<Label> label,
	std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
	int(*randomFunction)(int, int))
	: LabelDecoratorBase(label), randomFunction(randomFunction)
{
	initializeTransformations(textTranformations);
}

RandomTransformationDecoratorBase::RandomTransformationDecoratorBase
(std::unique_ptr<Label> label,
	std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
	int(*randomFunction)(int, int))
	: LabelDecoratorBase(std::move(label)), randomFunction(randomFunction)
{
	initializeTransformations(textTranformations);
}

std::string RandomTransformationDecoratorBase::getText() const
{
	// TODO:: Random Function should be inclusive
	int index = randomFunction(0, this->transformations.size() - 1);

	std::string str = this->sharedSubject != nullptr ?
		this->sharedSubject->getText() :
		this->movedSubject->getText();

	str = this->transformations[index]->transform(str);
	return str;
}
