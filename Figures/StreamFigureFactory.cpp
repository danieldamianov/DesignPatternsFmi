#include "StreamFigureFactory.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <cassert>

void StreamFigureFactory::readLine(std::string& var)
{
	if (externalStream == nullptr)
	{
		std::getline(*stealedStream, var);
		return;
	}

	std::getline(*externalStream, var);
}

std::vector<std::string> StreamFigureFactory::getPartsFormInput(std::string input)
{
	std::vector<std::string> parts;
	std::string currentPart;

	for (char c : input) {
		if (c != ' ') {
			currentPart += c;
		}
		else if (!currentPart.empty()) {

			parts.push_back(currentPart);
			currentPart.clear();
		}
	}

	if (!currentPart.empty()) {
		parts.push_back(currentPart);
	}

	return parts;
}

std::unique_ptr<Figure> StreamFigureFactory::createFigure()
{
	std::string input;
	readLine(input);

	if (validateInput(input) == false)
	{
		return nullptr;
	}

	std::vector<std::string> inputParts = getPartsFormInput(input);

	return getFigure(inputParts);
}

std::unique_ptr<Figure> StreamFigureFactory::getFigure(std::vector<std::string>& inputParts)
{
	if (inputParts[0] == "circle")
	{
		double radius = std::stod(inputParts[1]);

		return std::make_unique<Circle>(radius);
	}
	else if (inputParts[0] == "rectangle")
	{
		double a = std::stod(inputParts[1]);
		double b = std::stod(inputParts[2]);

		return std::make_unique<Rectangle>(a, b);
	}
	else if (inputParts[0] == "triangle")
	{
		double x = std::stod(inputParts[1]);
		double y = std::stod(inputParts[2]);
		double z = std::stod(inputParts[3]);

		return std::make_unique<Triangle>(x, y, z);
	}

	assert(false);
	return nullptr;
}
