#include "InputLabel.h"

// The shallow copy of the label is OK!

InputLabel::InputLabel(Color color, Font font, std::istream& stream)
    : label(color, font, ""), requestsLeft(0), stream(stream)
{ }

std::string InputLabel::getHelperText()
{
    // TODO:: Implement the bridge pattern here!
    return std::string();
}

void InputLabel::setHelperText(std::string text)
{
    // TODO:: Implement the bridge pattern here!
}

std::string InputLabel::getText() const
{
    if (requestsLeft == 0)
    {
        std::string newText;
        stream >> newText;

        label = RichLabel(label.getColor(), label.getFont(), newText);

        requestsLeft = requestsTimeout;
    }
    
    requestsLeft--;
    return label.getText();
}
