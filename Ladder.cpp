#include "Ladder.h"


std::ostream& operator<<(std::ostream& out, Ladder& ladder)
{
    out << "Ladder Details:\n";
    out << "ID: " << ladder.getIDNumber() << "\n";
    out << "Orginal Cost: " << ladder.getCost() << "\n";
    out << "Height: " << ladder.getHeight() << "\n";
    out << "Style: " << ladder.getStyle() << "\n";
    out << "Weight Limit: " << ladder.getWeight_Limit() << "\n";
    return out;
}
Ladder::Ladder():Equipment()
{
	height = 0;
	style = "";
	Weight_Limit = 0;
}

Ladder::Ladder(const Ladder& lad) : Equipment(lad)
{
	this->height = lad.height;
	this->style = lad.style;
	this->Weight_Limit = lad.Weight_Limit;
}
Ladder::Ladder(float h, std::string s, int w)
{
	height = h;
	style = s;
	Weight_Limit = w;
}

Ladder::~Ladder()
{
    // Destructor logic if needed
}

void Ladder::setHeight(float Height)
{
    this->height = Height;
}

void Ladder::setStyle(std::string style)
{
    this->style = style;
}

void Ladder::setWeight_limit(int Limit)
{
    this->Weight_Limit = Limit;
}

float Ladder::getHeight() const
{
    return this->height;
}

std::string Ladder::getStyle() const
{
    return this->style;
}

int Ladder::getWeight_Limit() const
{
    return this->Weight_Limit;
}