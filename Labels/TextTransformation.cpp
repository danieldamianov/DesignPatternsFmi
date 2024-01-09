#include "TextTransformation.h"

bool TextTransformation::equals(TextTransformation& other) const
{
	if (typeid(*this) != typeid(other))
	{
		return false;
	}

	return true;
}
