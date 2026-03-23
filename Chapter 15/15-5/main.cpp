//Exercise 15.6: Test your print_total function from the exercises in §
//15.2.1 (p. 595) by passing both Quote and Bulk_quote objects o that
//function.

#include <ostream>
#include <iostream>
#include "Bulk_quote.h"

double print_total(std::ostream& os, const Quote &item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() <<" # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

//int main()
//{
////    Quote quote("book",10.5);
////    Bulk_quote b_quote("book",10.5,10,50.0);
////    print_total(std::cout,quote,11);
////    print_total(std::cout,b_quote,11);
//    Bulk_quote bq1;
//    Bulk_quote bq2("ss",2.05,12,0.3);
//    bq2 = std::move(bq2);
//    return 0;
//}
