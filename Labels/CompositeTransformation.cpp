#include "CompositeTransformation.h"

CompositeTransformation::CompositeTransformation(std::vector<std::unique_ptr<TextTransformation>>& transformations)
{
	for (int i = 0; i < transformations.size(); i++)
	{
		this->transformations.push_back(std::move(transformations[i]));
	}
}

std::string CompositeTransformation::transform(std::string text) const
{
	std::string textResult = text;

	for (int i = 0; i < this->transformations.size(); i++)
	{
		textResult = this->transformations[i]->transform(textResult);
	}

	return textResult;
}

bool CompositeTransformation::equals(TextTransformation& other) const
{
	if (typeid(*this) != typeid(other))
	{
		return false;
	}

	CompositeTransformation& newPointer = (dynamic_cast<CompositeTransformation&>(other));

	if (this->transformations.size() != newPointer.transformations.size())
	{
		return false;
	}

	for (int i = 0; i < this->transformations.size(); i++)
	{
		if (this->transformations[i]->equals(*newPointer.transformations[i]) == false)
		{
			return false;
		}
	}

	return true;
}
