// Figures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TextTransformationDecoratorBase.h"
#include "TextTransformationDecoratorMovedObject.h"
#include "TextTransformationDecoratorSharedObject.h"
#include "RandomTransformationDecoratorSharedObject.hpp"
#include "RandomTransformationDecoratorMovedObject.hpp"
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

// TODO:: CHECK THE ENTIRE PROGRAM FOR VALID PARAMATERS WHICH ARE POINTERS! - THEY SHOULDN'T be NULLPTR!

int main()
{
	std::unique_ptr<TextTransformation> capitalizeTransformation
		= std::make_unique<CapitalizeTransformation>();
	std::unique_ptr<TextTransformation> leftTrimTransformation
		= std::make_unique<LeftTrimTransformation>();
	std::unique_ptr<TextTransformation> rightTrimTransformation
		= std::make_unique<RightTrimTransformation>();

	std::unique_ptr<TextTransformation> capitalizeTransformation2
		= std::make_unique<CapitalizeTransformation>();
	std::unique_ptr<TextTransformation> leftTrimTransformation2
		= std::make_unique<LeftTrimTransformation>();
	std::unique_ptr<TextTransformation> rightTrimTransformation2
		= std::make_unique<RightTrimTransformation>();

	//std::shared_ptr<Label> richLabel = std::make_shared<RichLabel>
	//	(Color::Blue, Font::BookmanOldStyle, "        test         ");


	// TODO:: SEE WHAT HAPPENS IF THE RICHLABEL IS SHARED POINTER AND THE REMOVE DECPRATOR IS CALLED!!!

	std::unique_ptr<Label> richLabel = std::make_unique<RichLabel>
		(Color::Blue, Font::BookmanOldStyle, "        test         ");

	std::weak_ptr<IRandomFunctionProvider> provider = RandomNumberProvider::getInstance();

	//int (RandomNumberProvider::*randomFunctionPointer)(int, int) = &RandomNumberProvider::getRandomNumberInRange;
	//int a = randomFunctionPointer(4, 5);
	//int a = (provider.*randomFunctionPointer)(4, 5);
	//std::vector<std::unique_ptr<TextTransformation>>* v = new std::vector<std::unique_ptr<TextTransformation>>();
	std::vector<std::unique_ptr<TextTransformation>> v;
	v.push_back(std::move(capitalizeTransformation));
	v.push_back(std::move(rightTrimTransformation));

	std::vector<std::unique_ptr<TextTransformation>> v2;
	v2.push_back(std::move(capitalizeTransformation2));
	v2.push_back(std::move(rightTrimTransformation2));

	std::unique_ptr<Label> decorator = std::make_unique<TextTransformationDecoratorMovedObject>
		(std::move(richLabel), std::move(leftTrimTransformation));
	
	decorator = std::make_unique<RandomTransformationDecoratorMovedObject>
		(std::move(decorator), v, provider);

	//LabelDecoratorBase* dec = new RandomTransformationDecoratorMovedObject(nullptr, v2, provider);
	//LabelDecoratorBase& decoratorPointer = &(*decorator);
	
	//std::cout << dec->equals(dynamic_cast<LabelDecoratorBase&>(*(decorator.release())));

	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;

	
	decorator = LabelDecoratorBase::removeDecoratorFrom
	(
		std::move(decorator), std::make_unique<TextTransformationDecoratorMovedObject>
		(nullptr, std::move(leftTrimTransformation2))
	);

	//decorator = LabelDecoratorBase::removeDecoratorFrom
	//(std::move(decorator), std::make_unique<RandomTransformationDecoratorMovedObject>(nullptr, v2, provider));

	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;
	std::cout << decorator->getText() << "end" << std::endl;


	//Label* a = decorator.release();
	//LabelDecoratorBase* derivedPtr = dynamic_cast<LabelDecoratorBase*>(a);
	//auto b = derivedPtr->getTransformationTypes();
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