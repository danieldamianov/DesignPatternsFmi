#pragma once
#include <string>
#include <memory>
#include <vector>

class Figure
{
protected:
	std::string representativeName;

	//TEST FOR MEMORY LEAK
	//TODO DELETE!!!! THIS SHIT
 	mutable int* a;
	// TODO :: CHECK FOR NERAVENSTVO NA TRIAGALNIKA

	std::vector<double> parameters;

	Figure()
	{
		(*this).a = new int[10000];
	}

	void sortParameters();

public:
	virtual double getPerimeter() const = 0;

	virtual std::unique_ptr<Figure> clone() const = 0;

	virtual std::string toString() const;

	virtual ~Figure() 
	{
		delete[]a;
	}

	std::string getRepresentativeName() const;

	bool equals(const Figure& other) const;

	static bool checkDoublesForEquality(double d1, double d2);

};

