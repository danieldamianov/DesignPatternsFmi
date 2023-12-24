#include "LabelDecoratorBase.h"

LabelDecoratorBase::LabelDecoratorBase(const Label& label) : subject(label)
{ }

std::string LabelDecoratorBase::getText() const
{
	return this->subject.getText();
}
