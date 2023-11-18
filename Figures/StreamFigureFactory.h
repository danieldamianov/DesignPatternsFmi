#pragma once
#include "IFigureFactory.h"
#include "memory"
#include <istream>

class StreamFigureFactory : public IFigureFactory
{
private:
	std::istream* externalStream;
	std::unique_ptr<std::istream> stealedStream;

	void readLine(std::string& var);

	static std::vector<std::string> getPartsFormInput(std::string input);
	static void getFigure(std::vector<std::string>& inputParts, Figure*& figure);

public:

	StreamFigureFactory(std::istream& stream) : externalStream(&stream), stealedStream(nullptr)
	{

	}

	StreamFigureFactory(std::unique_ptr<std::istream> stream)
	{
		this->externalStream = nullptr;
		this->stealedStream = std::move(stream);
	}

	virtual Figure* createFigure() override;
};

