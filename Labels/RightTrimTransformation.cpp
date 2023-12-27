#include "RightTrimTransformation.h"

std::string RightTrimTransformation::transform(std::string text) const
{
    size_t end = text.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : text.substr(0, end + 1);
}
