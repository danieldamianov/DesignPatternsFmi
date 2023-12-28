#include "TextTransformation.h"

bool TextTransformation::equals(TextTransformation& other)
{
	if (typeid(this) != typeid(other))
	{
		return false;
	}

	return true;
}
