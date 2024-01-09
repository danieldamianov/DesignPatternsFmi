#pragma once
#include "TextTransformation.h"
#include "vector"

class CompositeTransformation : public TextTransformation
{
private:
	std::vector<std::unique_ptr<TextTransformation>> transformations;

public:
	CompositeTransformation(std::vector<std::unique_ptr<TextTransformation>>& transformations);

	virtual std::string transform(std::string text) const override;

	virtual bool equals(TextTransformation& other) const override;
}
;

