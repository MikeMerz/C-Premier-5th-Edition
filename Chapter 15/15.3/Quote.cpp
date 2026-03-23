#include "Quote.h"

void Quote::debug()
{
    std::cout << "bookNo= " << bookNo << " price= " << price << std::endl;
}
double Quote::print_total(std::ostream& os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() <<" # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}
