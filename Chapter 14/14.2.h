//Exercise 14.2: Write declarations for the overloaded input, output, addition,
//and compound-assignment operators for Sales_data.
//Exercise 14.6: Define an output operator for your Sales_data class.
//Exercise 14.9: Define an input operator for your Sales_data class.
//Exercise 14.20: Define the addition and compound-assignment operators
//for your Sales_data class.
//Exercise 14.22: Define a version of the assignment operator that can assign
//a string representing an ISBN to a Sales_data.
//Exercise 14.45: Write conversion operators to convert a Sales_data to
//string and to double. What values do you think these operators should
//return?

#include <string>
#include <iostream>

struct Sales_data {
    friend std::ostream& operator<<(std::ostream& stream, const Sales_data& data);
    friend std::istream& operator>>(std::istream& stream, Sales_data& data);

    Sales_data():bookNo(""), units_sold(0), revenue(0.0) {}
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned num, double price): bookNo(s), units_sold(num), revenue(price*num) { }
    Sales_data(std::istream &is);
    std::string isbn() const { return bookNo; }

    Sales_data operator+(const Sales_data& other);
    Sales_data& operator+=(const Sales_data& other);
    Sales_data& operator=(const std::string& other);
    explicit operator std::string() const {return bookNo;}
    explicit operator double() const {return revenue;}

    std::string bookNo;
    unsigned units_sold;
    double revenue;
};
std::ostream& operator<<(std::ostream& stream, const Sales_data& data);
std::istream& operator>>(std::istream& stream, Sales_data& data);