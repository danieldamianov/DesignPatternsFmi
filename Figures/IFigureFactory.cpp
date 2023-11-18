#include "IFigureFactory.h"
#include <regex>

void IFigureFactory::recycleFigure(Figure* figure)
{
	delete figure;
}

bool IFigureFactory::validateInput(std::string input)
{
	std::regex pattern(R"(\s*(circle|rectangle|triangle)\s+([\d.]+)\s*([\d.]+)?\s*([\d.]+)?\s*)");

	std::smatch match;

	if (std::regex_match(input, match , pattern) == false)
	{
		return false;
	}

	if (match[1] == "circle" && (match[2].str().empty() || match[3].str().empty() == false || match[4].str().empty() == false)) return false;
	if (match[1] == "rectangle" &&
		(
			match[2].str().empty() ||
			(match[3].str().empty() == false && match[4].str().empty() == false) || 
			(match[3].str().empty() && match[4].str().empty())
		)
		) return false;
	if (match[1] == "triangle" && (match[2].str().empty() || match[3].str().empty() || match[4].str().empty())) return false;

	return true;
}
