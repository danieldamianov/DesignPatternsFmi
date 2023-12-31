﻿// Figures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "FigureFactorySupplier.h"
#include "NonPositiveParameterException.h"
#include "TriangleInequalityException.h"
#include <iostream>

// Uncomment these lines and comment the main function to execute the unit tests.

//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "doctest.h"
//#include "CircleTests.hpp"
//#include "TriangleTests.hpp"
//#include "RandomFigureFactoryTests.hpp"
//#include "StreamFigureFactoryTests.hpp"
//#include "RectangleTests.hpp"

void initializeFile();

// I chose to work only with smart pointers in the whole program because i wanted to be consistent. 
// At first i implemented the factories allocating their objects with the "new" operator, returning basic pointer,
// and then special method had to be called to recycle the created object.
// But then i decided that the whole program should work woth smart pointers only for consostency.

int main()
{
	//initializeFile();

	FigureFactorySupplier figureFactorySupplier;

	while (true)
	{
		std::string numberOfFiguresInput = "-1";

		while (figureFactorySupplier.validateNumberOrStop(numberOfFiguresInput) == false)
		{
			std::cout << "Enter number of figures or STOP: ";
			std::cin >> numberOfFiguresInput;
			std::cin.get();
		}

		if (numberOfFiguresInput == "STOP")
		{
			break;
		}

		int numberOfFigures = stoi(numberOfFiguresInput);

		std::vector<std::unique_ptr<Figure> > figures;

		// options for initializing the figures:
		// 1 option:STDIN
		// 2 option:FILE {fileName}
		// 3 option:RANDOM

		std::cout << "Enter way of entering figures:" << std::endl;
		std::cout << "Options: " << std::endl;
		std::cout << "STDIN" << std::endl;
		std::cout << "FILE {fileName}" << std::endl;
		std::cout << "RANDOM" << std::endl;
		std::cout << "STOP - exits the program" << std::endl;

		std::string input = "invalid input";

		while (figureFactorySupplier.validateInputOption(input) == false)
		{
			std::getline(std::cin, input);
		}

		std::cout << "If you entered STDIN, enter the number of figures that ypu specified in the format:" << std::endl;
		std::cout << "{figure type} {p1} {p2} {p3}, where p2 and p3 are optional" << std::endl;

		std::unique_ptr<IFigureFactory> factory = figureFactorySupplier.getFactory(input);

		for (int i = 0; i < numberOfFigures; i++)
		{

			try
			{
				std::unique_ptr<Figure> figure = factory->createFigure();

				if (figure == nullptr)
				{
					std::cout << "Could't read figure, because the input was not in the correct format!" << std::endl;
					std::cout << "If you entered the figure from the standart input, know that the figure is not added!" << std::endl;
					std::cout << "If you chose to read the figures from a file, check the content of the file and know that the figure is not added!" << std::endl;
				}
				else
				{
					figures.push_back(std::move(figure));
				}

			}
			catch (const NonPositiveParameterException& ex)
			{
				std::cout << "Invalid figure parameters!" << std::endl;
				std::cout << "Figure was not added!" << std::endl;
				std::cout << ex.what() << std::endl;

			}
			catch (const TriangleInequalityException& ex)
			{
				std::cout << "Invalid triangle inequality exception!" << std::endl;
				std::cout << "Triangle was not added!" << std::endl;
				std::cout << ex.what() << std::endl;
			}
		}

		for (int i = 0; i < figures.size(); i++)
		{
			std::cout << figures[i]->toString() << std::endl;
		}

	}
}


void initializeFile()
{
	std::ofstream stream("figures.txt", std::ios_base::trunc);

	stream << "circle 37.5";               stream << std::endl;
	stream << "rectangle 14.2 92.8";	   stream << std::endl;
	stream << "triangle 5.3 77.1 60.4";	   stream << std::endl;
	stream << "circle 20.6";			   stream << std::endl;
	stream << "rectangle 87.3 11.9";	   stream << std::endl;
	stream << "triangle 30.7 41.2 71.8";   stream << std::endl;
	stream << "circle 45.9";			   stream << std::endl;
	stream << "rectangle 63.4 82.7";	   stream << std::endl;
	stream << "triangle 2.6 91.4 13.2";	   stream << std::endl;
	stream << "circle 70.2";			   stream << std::endl;
	stream << "rectangle 18.8 48.9";	   stream << std::endl;
	stream << "triangle 84.7 29.3 8.1";	   stream << std::endl;
	stream << "circle 10.5";			   stream << std::endl;
	stream << "rectangle 96.8 3.2";		   stream << std::endl;
	stream << "triangle 50.6 75.9 20.1";   stream << std::endl;
	stream << "circle 33.4";			   stream << std::endl;
	stream << "rectangle 61.7 16.4";	   stream << std::endl;
	stream << "triangle 40.2 55.8 90.3";   stream << std::endl;
	stream << "circle 88.1";			   stream << std::endl;
	stream << "rectangle 8.9 42.6";		   stream << std::endl;
	stream << "triangle 73.5 12.7 66.4";   stream << std::endl;
	stream << "circle 54.7";			   stream << std::endl;
	stream << "rectangle 37.1 67.9";	   stream << std::endl;
	stream << "triangle 95.2 23.8 58.6";   stream << std::endl;
	stream << "circle 27.3";			   stream << std::endl;
	stream << "rectangle 78.4 7.6";		   stream << std::endl;
	stream << "triangle 32.9 19.4 44.1";   stream << std::endl;
	stream << "circle 96.5";			   stream << std::endl;
	stream << "rectangle 55.3 33.7";	   stream << std::endl;
	stream << "triangle 68.1 91.6 14.3";   stream << std::endl;
	stream << "circle 11.8";			   stream << std::endl;
	stream << "rectangle 29.5 84.2";	   stream << std::endl;
	stream << "triangle 59.7 5.8 72.4";	   stream << std::endl;
	stream << "circle 45.1";			   stream << std::endl;
	stream << "rectangle 21.8 93.7";	   stream << std::endl;
	stream << "triangle 3.7 48.6 89.1";	   stream << std::endl;
	stream << "circle 70.9";			   stream << std::endl;


	stream.close();
}
