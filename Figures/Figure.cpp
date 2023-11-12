#include "Figure.h"

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
