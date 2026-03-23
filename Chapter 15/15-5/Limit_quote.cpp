#include "Limit_quote.h"

double Limit_quote::net_price(std::size_t n) const
{
    return n > max_qty ? max_qty * price * discount + ((n - max_qty) * price) : n * price * discount;
}

void Limit_quote::debug()
{
//    Quote::debug();
    std::cout << "max_qty= " << max_qty << " discount= " << discount << std::endl;
}

