#include "Bulk_quote.h"

double Bulk_quote::net_price(std::size_t n) const
{
    return n * price * (n < min_qty ? 1 : 1 - discount);
}

void Bulk_quote::debug()
{
//    Quote::debug();
    std::cout << "min_qty= " << min_qty << " discount= " << discount << std::endl;
}
