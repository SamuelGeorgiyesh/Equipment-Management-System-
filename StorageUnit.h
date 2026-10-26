#pragma once
#include"Date.h"
#include "Ladder.h"
#include "Scaffold.h"
#include <vector>
#include <iostream>
#include <iomanip>

template <typename data> class StorageUnit
{



public:

	StorageUnit();

	~StorageUnit();
	void setDescription(std::string description);
	void setUnitID(std::string unitID); // Setter for UnitID
	void setLength(float length);
	void setWidth(float width);
	void sethight(float height);
	void setCostperMonth(double costpermon);
	void setDate(Date& date);
	void setautoRenew(bool autoRenew);
	void setHumidty(bool humitdty);
	//getters
	std::string getUnitID() const;
	std::string getDescription() const;
	float getLength() const;
	float getWidth() const;
	float gethight() const;
	double getCostperMonth() const;
	Date getDate() const;
	bool getautoRenew() const;
	bool getHumidty() const;
	bool isDuplicateID(std::string IDnum) const;


	//other fuctions
	void AddEquipment(const data& equipment);
	bool removeInventory(std::string IDnum);
	void printInventory();
	void printGeneralInfo();

private:
	std::string description;
	std::vector <data>  EquipmentType;
	std::string UnitID;
	float length;
	float width;
	float height;
	double costPerMonth;
	Date date;
	bool autoRenew;
	bool HumidityControlled;



};

template<typename data>
void StorageUnit<data>::setDescription(std::string description)
{
	this->description = description;
}


template<typename data>
StorageUnit<data>::StorageUnit()
{
	this->length = 0;
	this->width = 0;
	this->height = 0;
	this->costPerMonth = 0;
	this->date;
	this->autoRenew = false;
	this->HumidityControlled = false;
}

template<typename data>
StorageUnit<data>::~StorageUnit()
{

}
template<typename data>
void StorageUnit<data>::setUnitID(std::string unitID) 
{ 
	UnitID = unitID;
} // Setter for UnitID

template<typename data>
void StorageUnit<data>::setLength(float length)
{
	if (length < 0) {
		std::cerr << "Error: Length cannot be negative.\n";
		return;
	}
	this->length = length;
}
template<typename data>
void StorageUnit<data>::setWidth(float width)
{
	if (width < 0) {
		std::cerr << "Error: Width cannot be negative.\n";
		return;
	}
	this->width = width;
}
template<typename data>
void StorageUnit<data>::sethight(float height)
{
	if (height < 0) {
		std::cerr << "Error: Height cannot be negative.\n";
		return;
	}
	this->height = height;
}
template<typename data>
void StorageUnit<data>::setCostperMonth(double costpermon)
{
	if (costPerMonth < 0) {
		std::cerr << "Error: Cost per month cannot be negative.\n";
		return;
	}
	this->costPerMonth = costPerMonth;
}
template<typename data>
void StorageUnit<data>::setDate(Date& date)
{
	this->date = date;
}
template<typename data>
void StorageUnit<data>::setautoRenew(bool autoRenew)
{
	this->autoRenew = autoRenew;
}
template<typename data>
void StorageUnit<data>::setHumidty(bool humitdty)
{
	this->HumidityControlled = humitdty;
}
//getters
template<typename data>
float StorageUnit<data>::getLength() const
{
	return length;
}
template<typename data>
float StorageUnit<data>::getWidth() const
{
	return width;
}
template<typename data>
float StorageUnit<data>::gethight() const
{
	return height;
}
template<typename data>
double StorageUnit<data>::getCostperMonth() const
{
	return costPerMonth;
}
template<typename data>
std::string StorageUnit<data>::getDescription() const
{ 
	return description;
}
template<typename data>
Date StorageUnit<data>::getDate() const
{
	return date;
}
template<typename data>
bool StorageUnit<data>::getautoRenew() const
{
	return autoRenew;
}
template<typename data>
bool StorageUnit<data>::getHumidty() const
{
	return HumidityControlled;
}

template<typename data>
bool StorageUnit<data>::isDuplicateID(std::string IDnum) const {
	for (const auto& data : EquipmentType) {
		if (data.getIDNumber() == IDnum) { // Assuming `data` has a `getIDNumber` method
			return true; // Duplicate ID found
		}
	}
	return false; // No duplicate ID found
}

template<typename data>
void StorageUnit<data>::AddEquipment(const data& equipment)
{
std::string IDnum = equipment.getIDNumber(); // Assuming `data` has a `getIDNumber` method
if (isDuplicateID(IDnum)) {
	return;
}
EquipmentType.push_back(equipment);
}

template<typename data>
bool StorageUnit<data>::removeInventory(std::string IDnum)
{
	for (int i = 0; i < EquipmentType.size(); i++)
	{
		//check for idNumbers in the vector 
		if (EquipmentType[i].getIDNumber() == IDnum) // Missing condition
		{
			EquipmentType.erase(EquipmentType.begin() + i); 
			
			// Remove the equipment
			return true;// Exit loop after removal
		}
		
	}
	return false;
}
template<typename data>  
std::string StorageUnit<data>::getUnitID() const  
{  
   return UnitID; // Corrected to use the properly declared member variable 'UnitID'  
}
template<typename data>
void StorageUnit<data>::printInventory() {
	for (const auto& equipment : EquipmentType) {
		std::cout << equipment << std::endl; // Assuming `operator<<` is overloaded for `data`
	}
}
template<typename data>
void StorageUnit<data>::printGeneralInfo()
{
std::cout << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
std::cout << "Unit ID: " << getUnitID() << std::endl;
std::cout << "Description: " << getDescription() << std::endl;
std::cout << "Dimensions " << std::endl;
std::cout << "Length: " << getLength() << std::endl;
std::cout << "Width: " << getWidth() << std::endl;
std::cout << "Height: " << gethight() << std::endl;
if (getHumidty() == true)
{
	std::cout << "**Unit is  Humidity Controlled.\n";
}
else
{
	std::cout << "*Unit is not Humidity Controlled.\n";
}
std::cout << "Cost per Month: " << getCostperMonth() << std::endl;
std::cout << "Date Signed " << getDate() << std::endl;
if (getautoRenew() == true)
{
	std::cout << "**Contract does auto-renew.\n";
}
else
{
	std::cout << "*Contract does not auto-renew.\n";
}

//add rental con
}
