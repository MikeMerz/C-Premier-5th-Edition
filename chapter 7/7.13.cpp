#include <iostream>
#include <string>
/* Exercise 7.13: Rewrite the program from page 255 to use the istream
constructor. */
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

int main() {
    Sales_data total(std::cin);
    if (std::cin) {
        Sales_data trans(std::cin);
        while (std::cin) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(std::cout,total);
                total = trans;
            }
            read(std::cin, trans);
        }
        print(std::cout,total);
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }

    return 0;
}