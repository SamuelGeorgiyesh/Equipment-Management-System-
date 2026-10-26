#pragma once
#include "Equipment.h"
class Ladder : public Equipment
{
public:
	friend std::ostream& operator<<(std::ostream& out, Ladder&);
	//constructors 

	Ladder();
	Ladder(const Ladder& lad);
	Ladder(float h, std::string s, int w);
	~Ladder();

	//setters and getters 

	void setHeight(float Height);
	void setStyle(std::string style);
	void setWeight_limit(int Limit);
	float getHeight() const;
	std::string getStyle() const;
	int getWeight_Limit() const;




private:
	float height;
	std::string style;
	int Weight_Limit;


};

