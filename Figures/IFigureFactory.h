#pragma once
#include "Figure.h"

class IFigureFactory
{
protected:
	// TODO :: CHECK FOR NERAVENSTVO NA TRIAGALNIKA
	static bool validateInput(std::string input);

public:
	virtual Figure* createFigure() = 0;

	// TODO: CHECK IN ALL PLACES OF CODE IF I RECYCLE ALL THE FIGURES!!!!
	// I decided to delete figures using this method and not smart pointers because 
	// i believe that if an object is created in the factory, it is factory's job to destroy it
	// However there is an option to copy the objects and get a smart pointer to the copy.
	// This will be useful if someone doesn't want to depend on the factory once the object is created
	// Then, they should be careful when the object is destroyed(the unique pointer gets out of scope)
	// But generally the figures which are created in the factory must be destroyed there to prevent memory leaks.
	// Another reason that i chose this method is that i prefer to have maximal control over that 
	// when an object is destroyed, which is native to c++
	void recycleFigure(Figure* figure);

	virtual ~IFigureFactory() { }
};

