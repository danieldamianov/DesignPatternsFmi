#include "CapitalizeTransformation.h"

std::string CapitalizeTransformation::transform(std::string text) const
{
    text[0] = std::toupper(text[0]);
    return text;
}

