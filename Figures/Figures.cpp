// Figures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FigureFactorySupplier.h"

// TODO:: CHECK FOR ENCAPSULATION OF PRIVATE MEMBERS THE WHOLE PROGRAM
// TODO:: CHECK FOR EXCEPTION SAFETY THE ENTIRE PROGRAM!!!!

// options for initializing the figures:
// 1 option:STDIN
// 2 option:FILE {fileName}
// 3 option:RANDOM {numberOfFigures}
int main()
{
	while (true)
	{
		IFigureFactory* randomFactory = nullptr;

		try
		{
			randomFactory = FigureFactorySupplier::getFactory("RANDOM");

			Figure* figure = randomFactory->createFigure();

			std::cout << figure->toString();

			randomFactory->recycleFigure(figure);
		}
		catch (std::exception& ex)
		{
			FigureFactorySupplier::recycleFactory(randomFactory);
		}
		//IClonable* circleAsClonable = new Circle(3);
		//delete circleAsClonable
	}
	
}
