#pragma once
class IRandomFunctionProvider
{
public:
	virtual int getRandomNumberInRange(int min, int max) = 0;
};

