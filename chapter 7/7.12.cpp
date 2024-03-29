#include <iostream>
#include <string>
/* Exercise 7.12: Move the definition of the Sales_data constructor that
takes an istream into the body of the Sales_data class. */
struct Sales_data {
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned num, double price): bookNo(s), units_sold(num), revenue(price*num) { }
    Sales_data(std::istream &is);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
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

int main()
{
    //Default con
    Sales_data ImDefualtSales;
    //Second Con
    std::string s("30-11-2023-A");
    Sales_data bookCon(s);
    //Third Con
    Sales_data thirdCon(s, 20, 10.5);
    //Fourth Con
    Sales_data fourthCon(std::cin);
}