#include "StreamFigureFactory.h"
#include "InvalidFigureTypeException.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

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

// TODO :: add validation of the int parameters!
Figure* StreamFigureFactory::createFigure()
{
	Figure* figure = nullptr;
	std::string input;
	readLine(input);

	// TODO :: CHECK IN THE CALLER CODE FOR NULLPTR!
	if (validateInput(input) == false)
	{
		// TODO:: CHANGE WITH SMART POINTER
		return nullptr;
	}

	std::vector<std::string> inputParts = getPartsFormInput(input);

	getFigure(inputParts, figure);

	return figure;
}

void StreamFigureFactory::getFigure(std::vector<std::string>& inputParts, Figure*& figure)
{
	if (inputParts[0] == "circle")
	{
		double radius = std::stod(inputParts[1]);

		figure = new Circle(radius);
	}
	else if (inputParts[0] == "rectangle")
	{
		double a = std::stod(inputParts[1]);
		double b = std::stod(inputParts[2]);

		figure = new Rectangle(a, b);
	}
	else if (inputParts[0] == "triangle")
	{
		double x = std::stod(inputParts[1]);
		double y = std::stod(inputParts[2]);
		double z = std::stod(inputParts[3]);

		figure = new Triangle(x, y, z);
	}
	else // THINK AGAIN IF THIS IS THE PROPER INPLEMENTATION!
	{
		throw InvalidFigureTypeException("Stream provided an invalid figure type!");
	}
}
