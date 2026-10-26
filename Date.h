#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>

class Date
{
    friend std::ostream& operator<<(std::ostream& output, const Date& d);
    friend std::istream& operator>>(std::istream& input, Date& d); // Add this line

public:
    Date(int d = 0, int m = 0, int yyyy = 0)
    {
        setDate(d, m, yyyy);
    }
    ~Date() {}
    void setDate(int d, int m, int yyyy)
    {
        day = d;
        month = m;
        year = yyyy;
    }

private:
    int day;
    int month;
    int year;
};

// Overload the output operator
inline std::ostream& operator<<(std::ostream& output, const Date& d)
{
    output << d.month << "/" << d.day << "/" << d.year;
    return output;
}

// Overload the input operator
inline std::istream& operator>>(std::istream& input, Date& d)
{
    char separator1, separator2;
    input >> d.month >> separator1 >> d.day >> separator2 >> d.year;
    if (separator1 != '/' || separator2 != '/')
    {
        input.setstate(std::ios::failbit); // Set fail state if format is invalid
    }
    return input;
}


