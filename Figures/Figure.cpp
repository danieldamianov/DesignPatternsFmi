#include "Figure.h"
#include "NonPositiveParameterException.h"
#include <algorithm>
#include <cmath>

void Figure::sortParameters()
{
	std::sort(parameters.begin(), parameters.end());
}

void Figure::ensureParameterIsPositive(double number, std::string parameter) const
{
	if (number <= 0)
	{
		throw NonPositiveParameterException("Parameter " + parameter + " is non negative!");
	}
}

std::string Figure::toString() const
{
	std::string result;

	result += this->representativeName;

	for (int i = 0; i < this->parameters.size(); i++)
	{
		result += " ";
		result += std::to_string(this->parameters[i]);
	}

	return result;
}

std::string Figure::getRepresentativeName() const
{
	return this->representativeName;
}

bool Figure::equals(const Figure& other) const
{
	if (this->representativeName != other.getRepresentativeName())
	{
		return false;
	}

	if (this->parameters.size() != other.parameters.size())
	{
		return false;
	}

	int size = this->parameters.size();

	for (int i = 0; i < size; i++)
	{
		if (checkDoublesForEquality(this->parameters[i], other.parameters[i]) == false)
		{
			return false;
		}
	}

	return true;
}

bool Figure::checkDoublesForEquality(double d1, double d2)
{
	return abs(d1 - d2) < 0.00001;
}
