#include "Bird.h"
#include <iostream>

void Bird::Read(std::ostream& ostream, std::istream& istream)
{
	Animal::Read(ostream, istream);

	ostream << "enter num of eggs: ";
	istream >> b_numEggs;
	ostream << "enter age: ";
	istream >> b_age;

}

void Bird::Write(std::ostream& ostream)
{
	Animal::Write(ostream);

	ostream << "number of eggs: " << b_numEggs << std::endl;
	ostream << "age: " << b_age << std::endl;

}
