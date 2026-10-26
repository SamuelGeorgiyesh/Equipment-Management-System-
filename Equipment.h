#pragma once
#include <string>
#include "Date.h"
class Equipment
{
	friend std::ostream& operator<<(std::ostream& out, const Equipment&);
	
public:
	Equipment& operator=(const Equipment& other);
	//default Constructor
	Equipment();
	// Constructor  
	Equipment(double cost, int useFul_Life, const std::string& ID_number, const Date& DatePurched);
	Equipment(const Equipment& n);

	// Destructor  
	~Equipment();

	// Setters  
	void setCost(double cost);
	void setUseFulLife(int useFul_Life);
	void setIDNumber(const std::string& ID_number);
	void setDatePurched(const Date& DatePurched);

	// Getters  
	double getCost() const;
	int getUseFulLife() const;
	std::string getIDNumber() const;
	Date getDatePurched() const;
	bool operator<(const Equipment& other) const;
private:
	double cost;
	int useFul_Life;
	std::string* ID_number;
	Date DatePurched;
};

