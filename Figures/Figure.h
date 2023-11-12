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
 	//mutable int* a;
	// TODO :: CHECK FOR NERAVENSTVO NA TRIAGALNIKA

	std::vector<double> parameters;

public:
	virtual double getPerimeter() const = 0;

	virtual std::unique_ptr<Figure> clone() const = 0;

	virtual std::string toString() const;

	virtual ~Figure() { /*delete[]a;*/ }
};

