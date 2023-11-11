#include "IFigureFactory.h"

void IFigureFactory::recycleFigure(Figure* figure)
{
	delete figure;
}
