#pragma once
#include "Equipment.h"
class Scaffold : public Equipment
{
public:
	friend std::ostream& operator<<(std::ostream& out, Scaffold& sacffold);
	// Constructors
   
	Scaffold();
	
	Scaffold(float length, float width, float height, int weightLimit);
	~Scaffold();

	// Copy constructor
	Scaffold(const Scaffold& scaf);
	
    // Setters
    void setLength(float length);
    void setWidth(float width);
    void setHeight(float height);
    void setWeightLimit(int weightLimit);

    // Getters
    float getLength() const;
    float getWidth() const;
    float getHeight() const;
    int getWeightLimit() const;

private:
	float Length;
	float width;
	float height;
	int weightLimit;
};

