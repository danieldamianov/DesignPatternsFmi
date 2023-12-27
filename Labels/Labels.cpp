// Figures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TextTransformationDecoratorBase.h"
#include "TextTransformationDecoratorMovedObject.h"
#include "TextTransformationDecoratorSharedObject.h"
#include "RandomTransformationDecoratorSharedObject.hpp"
#include "CapitalizeTransformation.h"
#include "RightTrimTransformation.h"
#include "LeftTrimTransformation.h"
#include "RichLabel.h"
#include <random>
#include <functional>
#include <random>
#include "RandomNumberProvider.h"

// Uncomment these lines and comment the main function to execute the unit tests.
/*
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "RichLabelTests.hpp"
*/

int main()
{
	std::unique_ptr<TextTransformation> capitalizeTransformation
		= std::make_unique<CapitalizeTransformation>();
	std::unique_ptr<TextTransformation> leftTrimTransformation
		= std::make_unique<LeftTrimTransformation>();
	std::unique_ptr<TextTransformation> rightTrimTransformation
		= std::make_unique<RightTrimTransformation>();

	// TODO::MAKE SMARTPOINTER!
	// todo:: work in github repo
	std::shared_ptr<Label> richLabel = std::make_shared<RichLabel>
		(Color::Blue, Font::BookmanOldStyle, "test         ");

	std::weak_ptr<IRandomFunctionProvider> provider = RandomNumberProvider::getInstance();

	//int (RandomNumberProvider::*randomFunctionPointer)(int, int) = &RandomNumberProvider::getRandomNumberInRange;
	//int a = randomFunctionPointer(4, 5);
	//int a = (provider.*randomFunctionPointer)(4, 5);
	//std::vector<std::unique_ptr<TextTransformation>>* v = new std::vector<std::unique_ptr<TextTransformation>>();
	std::vector<std::unique_ptr<TextTransformation>> v;
	v.push_back(std::move(capitalizeTransformation));
	v.push_back(std::move(rightTrimTransformation));

	Label* obj = new RandomTransformationDecoratorSharedObject
	(richLabel, v, provider);

	std::cout << obj->getText() << "end" << std::endl;
	std::cout << obj->getText() << "end" << std::endl;
	std::cout << obj->getText() << "end" << std::endl;
	std::cout << obj->getText() << "end" << std::endl;
	std::cout << obj->getText() << "end" << std::endl;
	std::cout << obj->getText() << "end" << std::endl;
	std::cout << obj->getText() << "end" << std::endl;
	std::cout << obj->getText() << "end" << std::endl;
	std::cout << obj->getText() << "end" << std::endl;
	/*
	if (true)
	{
		std::unique_ptr<Label> decorator = std::make_unique<TextTransformationDecoratorSharedObject>
			(richLabel, std::move(leftTrimTransformation));

		decorator = std::make_unique<TextTransformationDecoratorMovedObject>
			(std::move(decorator), std::move(capitalizeTransformation));

		std::cout << decorator->getText() << std::endl;
	}
	std::cout << richLabel->getText(); // should print "    test"
	*/
	// TODO::DELETE THESE
	return 0;
}