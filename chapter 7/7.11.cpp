#include <iostream>
#include <string>
/* Exercise 7.11: Add constructors to your Sales_data class and write a
program to use each of the constructors */
class Sales_data {
    friend std::istream &read(std::istream &is, Sales_data &item);
    friend std::ostream &print(std::ostream &os, const Sales_data &item);
    friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned num, double price): bookNo(s), units_sold(num), revenue(price*num) { }
    Sales_data(std::istream &st);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

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
std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
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