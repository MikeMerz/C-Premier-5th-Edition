#include "Limit_quote.h"
double Limit_quote::net_price(std::size_t n) const
{
    return n > quantity ? quantity * price * discount + ((n - quantity) * price) : n * price * discount;
}

void Limit_quote::debug()
{
    Quote::debug();
    std::cout << "max_qty= " << quantity << " discount= " << discount << std::endl;
}