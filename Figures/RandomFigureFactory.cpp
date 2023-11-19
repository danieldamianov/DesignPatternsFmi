#include "RandomFigureFactory.h"
#include <ctime>
#include "InvalidRandomNumberException.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "cassert"
#include <cmath>

const int RandomFigureFactory::minSizeOfParameters = 1;
const int RandomFigureFactory::maxSizeOfParameters = 100;

// TODO :: Write Unit tests testing this method.
// The best way i can think of it is by mocking the random functonality
// This, however, requires altering the class so that it accepts a function pointer for the random function
// The idea between this is to test the method and not the random function, which is from the STD.

// TODO:: CHECK FOR VALID TRIANGLE INEQUALITY!!
Figure* RandomFigureFactory::createFigure()
{
	Figure* figure = nullptr;

	int lowerBoundInclusive;
	int upperBoundInclusive;

	int figureRandom = getRandomNumberInRange(1, 3);
	int p1 = 0, p2 = 0, p3 = 0;
	// TODO : Think about the case when t he new operator fails
	switch (figureRandom)
	{
		// Circle
	case 1:
		p1 = getRandomNumberInRange(minSizeOfParameters, maxSizeOfParameters);
		figure = new Circle(p1);
		break;
		// Triangle
	case 2:
		p1 = getRandomNumberInRange(minSizeOfParameters, maxSizeOfParameters);
		p2 = getRandomNumberInRange(minSizeOfParameters, maxSizeOfParameters);

		lowerBoundInclusive = abs(p1 - p2) + 1;
		upperBoundInclusive = p1 + p2 - 1;
		// int a = (1, 3); // CHECK WHAT THIS DOES!!!
		p3 = getRandomNumberInRange(max(minSizeOfParameters, lowerBoundInclusive),
			min(maxSizeOfParameters, upperBoundInclusive));
		figure = new Triangle(p1, p2, p3);
		break;
		//Rectangle
	case 3:
		p1 = getRandomNumberInRange(minSizeOfParameters, maxSizeOfParameters);
		p2 = getRandomNumberInRange(minSizeOfParameters, maxSizeOfParameters);
		figure = new Rectangle(p1, p2);
		break;

		// This code should never be reached!
	default:
		assert(false);
		throw InvalidRandomNumberException("Logical error in random generator.");
	}

	return figure;
}

// TODO::REFACTOR the first two rows are expensive
int RandomFigureFactory::getRandomNumberInRange(int minValue, int limit) {

	/*std::random_device dev;
	std::mt19937 rng(dev());*/
	std::uniform_int_distribution<std::mt19937::result_type> dist(minValue, limit);

	return dist(rng);
	//std::srand(static_cast<unsigned int>(std::time(nullptr)));

	//return rand() % limit + 1;
}

int RandomFigureFactory::max(int a, int b) {
	return (a > b) ? a : b;
}

int RandomFigureFactory::min(int a, int b) {
	return (a > b) ? b : a;
}
