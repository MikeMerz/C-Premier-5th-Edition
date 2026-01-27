#include "14.2.h"


std::ostream& operator<<(std::ostream& stream, const Sales_data& data)
{
    stream << data.isbn() << " " << data.units_sold << " " << data.revenue << std::endl;
    return stream;
}

std::istream& operator>>(std::istream& stream, Sales_data& data)
{
    double price = 0;
    stream >> data.bookNo >> data.units_sold >> price;
    if(stream)
        data.revenue = price * data.units_sold;
    else
        data = Sales_data();
    return stream;
}

Sales_data Sales_data::operator+(const Sales_data& other)
{
    Sales_data sum = other;
    sum+=other;
    return sum;
}

Sales_data& Sales_data::operator=(const std::string& other)
{
    *this = Sales_data(other);
    return *this;
}

Sales_data& Sales_data::operator+=(const Sales_data& other)
{
    units_sold += other.units_sold;
    revenue += other.revenue;
    return *(this);
}
