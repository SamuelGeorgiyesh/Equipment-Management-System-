#include "Equipment.h"
#include <stdexcept>
#include <iostream> // For error messages

//Question about dynamically allocated string where do i put it 

std::ostream& operator<<(std::ostream& out, const Equipment& k)
{
    out << "ID Number: " << k.getIDNumber() << std::endl;
    out << "Cost: " << k.getCost() << std::endl;
    out << "Date Of Purches: " << k.getDatePurched() << std::endl;
    out << "Product Life: " << k.getUseFulLife() << std::endl;
    return out;
}
//I have a questioned about this operator 
bool Equipment::operator<(const Equipment& other) const {
    return *ID_number < *other.ID_number;
}

//how does this work with the copy constructor 
Equipment& Equipment::operator=(const Equipment& other)
{
    if (this != &other) {
        cost = other.cost;
        useFul_Life = other.useFul_Life;
        delete ID_number;
        ID_number = new std::string(*other.ID_number); // Deep copy
        DatePurched = other.DatePurched;
    }
    return *this;
}

Equipment::Equipment()
{
    try {
        this->cost = 0.0;
        this->useFul_Life = 0;
        this->ID_number = new std::string(""); // Initialize with an empty string
        this->DatePurched = Date(); // Initialize with default Date
    }
    catch (const std::exception& e) {
        std::cerr << "Error initializing Equipment: " << e.what() << std::endl;
    }
}

// Constructor  
Equipment::Equipment(double cost, int useFul_Life, const std::string& ID_number, const Date& DatePurched)
{
    try {
        setCost(cost);
        setUseFulLife(useFul_Life);
        this->ID_number = new std::string(ID_number); // Properly initialize with the passed string
        this->DatePurched = DatePurched;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in Equipment constructor: " << e.what() << std::endl;
    }
}
//I have questioned about the copy constutor- did i do it right 
Equipment::Equipment(const Equipment& n)
{
    try {
        this->cost = n.cost;
        this->useFul_Life = n.useFul_Life;
        this->ID_number = new std::string(*n.ID_number); // Deep copy
        this->DatePurched = n.DatePurched;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in Equipment copy constructor: " << e.what() << std::endl;
    }
}

// Destructor  
Equipment::~Equipment()
{
    try {
        delete ID_number; // Free dynamically allocated memory
    }
    catch (const std::exception& e) {
        std::cerr << "Error in Equipment destructor: " << e.what() << std::endl;
    }
}

// Setters  
void Equipment::setCost(double cost)
{
    try {
        if (cost < 0) {
            throw std::invalid_argument("Cost cannot be negative.");
        }
        this->cost = cost;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in setCost: " << e.what() << std::endl;
    }
}

void Equipment::setUseFulLife(int useFul_Life)
{
    try {
        if (useFul_Life < 0) {
            throw std::invalid_argument("Useful life cannot be negative.");
        }
        this->useFul_Life = useFul_Life;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in setUseFulLife: " << e.what() << std::endl;
    }
}

void Equipment::setIDNumber(const std::string& ID_number)
{
    try {
        *(this->ID_number) = ID_number; // Update the value of the dynamically allocated string
    }
    catch (const std::exception& e) {
        std::cerr << "Error in setIDNumber: " << e.what() << std::endl;
    }
}

void Equipment::setDatePurched(const Date& DatePurched)
{
    try {
        this->DatePurched = DatePurched;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in setDatePurched: " << e.what() << std::endl;
    }
}

// Getters  
double Equipment::getCost() const
{
    return this->cost;
}

int Equipment::getUseFulLife() const
{
    return this->useFul_Life;
}

std::string Equipment::getIDNumber() const
{
    return *(this->ID_number); // Return the value of the dynamically allocated string
}

Date Equipment::getDatePurched() const
{
    return this->DatePurched;
}
