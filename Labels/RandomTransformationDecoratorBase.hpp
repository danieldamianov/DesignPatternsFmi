#pragma once
#include "LabelDecoratorBase.h"
#include "TextTransformation.h"
#include "IRandomFunctionProvider.h"
#include "vector"

class RandomTransformationDecoratorBase : public LabelDecoratorBase
{
private:
	std::vector<std::unique_ptr<TextTransformation>> transformations;
	std::weak_ptr<IRandomFunctionProvider> provider;

	void initializeTransformations
	(std::vector<std::unique_ptr<TextTransformation>>& transformations);

protected:
	RandomTransformationDecoratorBase(std::shared_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
		std::weak_ptr<IRandomFunctionProvider> provider);

	RandomTransformationDecoratorBase(std::unique_ptr<Label> label,
		std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
		std::weak_ptr<IRandomFunctionProvider> provider);

	virtual std::string getText() const override;
	
	virtual std::vector<const type_info*> getTransformationTypes() override;

	virtual bool equals(const std::unique_ptr<LabelDecoratorBase> other) override;
};

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
	std::weak_ptr<IRandomFunctionProvider> provider)
	: LabelDecoratorBase(label), provider(provider)
{
	initializeTransformations(textTranformations);
}

RandomTransformationDecoratorBase::RandomTransformationDecoratorBase
(std::unique_ptr<Label> label,
	std::vector<std::unique_ptr<TextTransformation>>& textTranformations,
	std::weak_ptr<IRandomFunctionProvider> provider)
	: LabelDecoratorBase(std::move(label)), provider(provider)
{
	initializeTransformations(textTranformations);
}

std::string RandomTransformationDecoratorBase::getText() const
{
	// TODO:: Random Function should be inclusive
	int index = provider.lock()->getRandomNumberInRange(0, this->transformations.size() - 1);

	std::string str = this->sharedSubject != nullptr ?
		this->sharedSubject->getText() :
		this->movedSubject->getText();

	str = this->transformations[index]->transform(str);
	return str;
}

std::vector<const type_info*> RandomTransformationDecoratorBase::getTransformationTypes()
{
	std::vector<const type_info*> infos;

	for (int i = 0; i < this->transformations.size(); i++)
	{
		infos.push_back(&typeid(*(this->transformations[i])));
	}

	return infos;
}

// TODO:: FIX
bool RandomTransformationDecoratorBase::equals(LabelDecoratorBase& other)
{
	if (typeid(this) != typeid(other))
	{
		return false;
	}

	std::unique_ptr<RandomTransformationDecoratorBase> newPointer
	(static_cast<RandomTransformationDecoratorBase*>(other));

	if (newPointer->transformations.size() != this->transformations.size())
	{
		return falseasd asdasd asdasd;
	}

	for (int i = 0; i < this->transformations.size(); i++)
	{
		if (this->transformations[i]->equals(*(newPointer->transformations[i])) == false)
		{
			return false;
		}
	}

	return true;
}

