#include "Scaffold.h"

std::ostream& operator<<(std::ostream& out, Scaffold& sacffold)
{
	out << "Scaffold Details:\n";
	out << "Length: " << sacffold.getLength() << "\n";
	out << "Width: " << sacffold.getWidth() << "\n";
	out << "Height: " << sacffold.getHeight() << "\n";
	out << "Weight Limit: " << sacffold.getWeightLimit() << "\n";
	return out;
}
Scaffold::Scaffold() : Equipment()
{
	this->Length = 0;
	this->width = 0;
	this->height = 0;
	this->weightLimit = 0;
}
//copy constructor question???
Scaffold::Scaffold(const Scaffold& scaf) : Equipment(scaf)
{
	this->Length = scaf.Length;
	this->width = scaf.width;
	this->height = scaf.height;
	this->weightLimit = scaf.weightLimit;
}
Scaffold::Scaffold(float length, float width, float height, int weightLimit) : Equipment()
{
	this->Length = length;
	this->width = width;
	this->height = height;
	this->weightLimit = weightLimit;
}
Scaffold::~Scaffold()
{
	// Destructor logic if needed
}
// Setters
void Scaffold::setLength(float length)
{
	this->Length = length;
}


void Scaffold::setWidth(float width)
{
	this->width = width;
}

void Scaffold::setHeight(float height)
{
	this->height = height;
}

void Scaffold::setWeightLimit(int weightLimit)
{
	this->weightLimit = weightLimit;
}

float Scaffold::getLength() const
{

	return height;
}

float Scaffold::getWidth() const
{
	return width;
}

float Scaffold::getHeight() const
{
	return height;
}

int Scaffold::getWeightLimit() const
{
	return weightLimit;
}
