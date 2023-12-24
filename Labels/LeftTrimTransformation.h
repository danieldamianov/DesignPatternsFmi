#pragma once
#include "TextTransformation.h"

class LeftTrimTransformation : public TextTransformation
{
    virtual std::string transform(std::string text) const override;
};

