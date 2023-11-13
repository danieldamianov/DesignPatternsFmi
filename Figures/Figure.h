#pragma once
#include <string>
#include <memory>
#include <vector>

class Figure
{
protected:
	std::string representativeName;

	// TODO :: CHECK FOR NERAVENSTVO NA TRIAGALNIKA

	std::vector<double> parameters;

	Figure() { }

	void sortParameters();

public:
	virtual double getPerimeter() const = 0;

	virtual std::unique_ptr<Figure> clone() const = 0;

	virtual std::string toString() const;

	virtual ~Figure() { }

	std::string getRepresentativeName() const;

	bool equals(const Figure& other) const;

	static bool checkDoublesForEquality(double d1, double d2);

};

