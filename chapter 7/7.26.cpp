//Exercise 7.26: Define Sales_data::avg_price as an inline function.

#include <string>
#include <iostream>

struct Sales_data {
    Sales_data():bookNo(""), units_sold(0), revenue(0.0) {}
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned num, double price): bookNo(s), units_sold(num), revenue(price*num) { }
    Sales_data(std::istream &is);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    inline double avg_price() const { return units_sold ?  revenue / units_sold : 0;}

    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

Sales_data::Sales_data(std::istream &is)
{
    read(is,*this);
}
Sales_data& Sales_data::combine(const Sales_data& other)
{
    units_sold += other.units_sold;
    revenue += other.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << std::endl;
    return os;
}

