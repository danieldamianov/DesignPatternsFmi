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
	static std::unique_ptr<Figure> getFigure(std::vector<std::string>& inputParts);

public:

	StreamFigureFactory(std::istream& stream) : externalStream(&stream), stealedStream(nullptr)
	{

	}

	StreamFigureFactory(std::unique_ptr<std::istream> stream)
	{
		this->externalStream = nullptr;
		this->stealedStream = std::move(stream);
	}

	virtual std::unique_ptr<Figure> createFigure() override;
};

