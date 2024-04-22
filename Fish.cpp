#include "Fish.h"
#include <iostream>

void Fish::Read(std::ostream& ostream, std::istream& istream)
{
	Animal::Read(ostream, istream);

	ostream << "enter length in inches: ";
	istream >> f_sizeInInches;
	ostream << "enter color: ";
	istream >> f_color;

}

void Fish::Write(std::ostream& ostream)
{
	Animal::Write(ostream);

	ostream << "length in inches: " <<f_sizeInInches << std::endl;
	ostream << "color: " << f_color << std::endl;

}
