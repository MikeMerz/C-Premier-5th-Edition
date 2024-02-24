//Exercise 10.17: Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a
//lambda in the call to sort instead of the compareIsbn function.

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

struct Sales_data {
    friend std::istream &read(std::istream &is, Sales_data &item);
    Sales_data():Sales_data("",0,0.0) {
        std::cout << "Sales_data() is called" << std::endl;
    }
    Sales_data(const std::string &s): Sales_data(s,0,0.0) {
        std::cout << "Sales_data(const std::string &s) is called" << std::endl;
    }
    Sales_data(const std::string &s, unsigned num, double price): bookNo(s), units_sold(num), revenue(price*num) {
        std::cout << "Sales_data()const std::string &s, unsinged num, double price) is called" << std::endl;
    }
    Sales_data(std::istream &is):Sales_data()
    {
        std::cout << "Sales_data(std::istream &is) is called" << std::endl;
        read(is,*this);
    }
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

Sales_data& Sales_data::combine(const Sales_data& other)
{
    units_sold += other.units_sold;
    revenue += other.revenue;
    Sales_data item = {"978-0590353403", 25, 15.99};
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

bool compareIsbn(const Sales_data &first, const Sales_data &sec)
{
    return first.isbn() < sec.isbn();
}
int main()
{
    Sales_data f("a"), f2("aa"), f3("aaa"), f4("aaaa");
    std::vector<Sales_data> vec{f,f2,f3,f4};
    std::sort(vec.begin(),vec.end(), [](const Sales_data &first, const Sales_data &sec){
        return first.isbn() < sec.isbn();
    });
    return 0;
}

