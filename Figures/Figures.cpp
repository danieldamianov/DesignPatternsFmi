// Figures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "FigureFactorySupplier.h"

// TODO:: CHECK FOR ENCAPSULATION OF PRIVATE MEMBERS THE WHOLE PROGRAM
// TODO:: CHECK FOR EXCEPTION SAFETY THE ENTIRE PROGRAM!!!!

// options for initializing the figures:
// 1 option:STDIN
// 2 option:FILE {fileName}
// 3 option:RANDOM

void initializeFile()
{
	std::ofstream stream("figures.txt", std::ios_base::trunc);

	stream << "circle 37.5				";
	stream << "rectangle 14.2 92.8		";
	stream << "triangle 5.3 77.1 60.4	";
	stream << "circle 20.6				";
	stream << "rectangle 87.3 11.9		";
	stream << "triangle 30.7 41.2 71.8	";
	stream << "circle 45.9				";
	stream << "rectangle 63.4 82.7		";
	stream << "triangle 2.6 91.4 13.2	";
	stream << "circle 70.2				";
	stream << "rectangle 18.8 48.9		";
	stream << "triangle 84.7 29.3 8.1	";
	stream << "circle 10.5				";
	stream << "rectangle 96.8 3.2		";
	stream << "triangle 50.6 75.9 20.1	";
	stream << "circle 33.4				";
	stream << "rectangle 61.7 16.4		";
	stream << "triangle 40.2 55.8 90.3	";
	stream << "circle 88.1				";
	stream << "rectangle 8.9 42.6		";
	stream << "triangle 73.5 12.7 66.4	";
	stream << "circle 54.7				";
	stream << "rectangle 37.1 67.9		";
	stream << "triangle 95.2 23.8 58.6	";
	stream << "circle 27.3				";
	stream << "rectangle 78.4 7.6		";
	stream << "triangle 32.9 19.4 44.1	";
	stream << "circle 96.5				";
	stream << "rectangle 55.3 33.7		";
	stream << "triangle 68.1 91.6 14.3	";
	stream << "circle 11.8				";
	stream << "rectangle 29.5 84.2		";
	stream << "triangle 59.7 5.8 72.4	";
	stream << "circle 45.1				";
	stream << "rectangle 21.8 93.7		";
	stream << "triangle 3.7 48.6 89.1	";
	stream << "circle 70.9				";
	stream << "rectangle 64.3 10.2		";
	stream << "triangle 37.9 51.6 66.8	";
	stream << "circle 22.4				";
	stream << "rectangle 89.7 4.3		";
	stream << "triangle 80.1 27.9 18.6	";
	stream << "circle 51.2				";
	stream << "rectangle 16.6 47.5		";
	stream << "triangle 63.8 72.3 11.4	";
	stream << "circle 36.7				";
	stream << "rectangle 98.2 2.9		";
	stream << "triangle 44.5 85.7 30.6	";
	stream << "circle 79.4				";
	stream << "rectangle 9.4 40.1		";
	stream << "triangle 61.2 14.6 76.9	";
	stream << "circle 29.9				";
	stream << "rectangle 76.8 18.3		";
	stream << "triangle 25.4 37.8 59.1	";
	stream << "circle 92.7				";
	stream << "rectangle 56.1 32.5		";
	stream << "triangle 13.9 70.2 48.3	";
	stream << "circle 16.2				";
	stream << "rectangle 45.8 79.6		";
	stream << "triangle 34.6 65.8 22.1	";
	stream << "circle 43.6				";
	stream << "rectangle 24.3 91.3		";
	stream << "triangle 87.6 50.1 11.3	";
	stream << "circle 71.8				";
	stream << "rectangle 69.2 8.7		";
	stream << "triangle 41.5 28.6 75.9	";
	stream << "circle 18.9				";
	stream << "rectangle 99.1 1.5		";
	stream << "triangle 56.3 82.4 19.7	";
	stream << "circle 48.3				";
	stream << "rectangle 11.7 44.9		";
	stream << "triangle 68.5 37.1 54.8	";
	stream << "circle 32.8				";
	stream << "rectangle 85.6 6.3		";
	stream << "triangle 23.1 59.6 43.2	";
	stream << "circle 96.2				";
	stream << "rectangle 53.2 34.8		";
	stream << "triangle 76.4 10.9 64.2	";
	stream << "circle 14.5				";
	stream << "rectangle 35.9 77.3		";
	stream << "triangle 49.2 68.3 15.7	";
	stream << "circle 59.1				";
	stream << "rectangle 22.7 92.1		";
	stream << "triangle 9.8 46.3 78.1	";
	stream << "circle 42.3				";
	stream << "rectangle 87.9 14.7		";
	stream << "triangle 33.4 57.1 81.9	";
	stream << "circle 74.6				";
	stream << "rectangle 63.9 13.5		";
	stream << "triangle 27.2 39.8 67.1	";
	stream << "circle 20.9				";
	stream << "rectangle 97.4 5.7		";
	stream << "triangle 52.3 72.6 31.4	";
	stream << "circle 54.1				";
	stream << "rectangle 16.7 46.5		";
	stream << "triangle 61.9 19.6 88.7	";
	stream << "circle 38.5				";
	stream << "rectangle 69.4 9.3		";
	stream << "triangle 36.1 53.7 76.5	";
	stream << "circle 91.8				";

	stream.close();
}

int main()
{
		initializeFile();

		while (true)
		{
			IFigureFactory* factory = nullptr;

			std::string input[2]{ "RANDOM", "FILE figures.txt"};

			int numberOfFigures = 5;

			std::vector<Figure*> figuresOriginals;
			std::vector<std::unique_ptr<Figure>> figureClones;

			for (int i = 0; i < 2; i++)
			{
				try
				{
					factory = FigureFactorySupplier::getFactory(input[i]);

					for (int j = 5 * i; j < 5 * i + 5; j++)
					{
						figuresOriginals.push_back(factory->createFigure());
					}

					for (int j = 5 * i; j < 5 * i + 5; j++)
					{
						figureClones.push_back(figuresOriginals[j]->clone());
					}

					for (int j = 5 * i; j < 5 * i + 5; j++)
					{
						factory->recycleFigure(figuresOriginals[j]);
					}

					FigureFactorySupplier::recycleFactory(factory);
				}
				// TODO: THINK THIS AGAIN
				catch (const std::exception& ex)
				{
					FigureFactorySupplier::recycleFactory(factory);
					throw ex;
				}

			}

			for (int i = 0; i < 10; i++)
			{
				std::cout << figureClones[i]->toString() << std::endl;
			}
		}
		

}
