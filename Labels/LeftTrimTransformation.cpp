#include "LeftTrimTransformation.h"

std::string LeftTrimTransformation::transform(std::string text) const
{
    size_t start = text.find_first_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : text.substr(start);
}
