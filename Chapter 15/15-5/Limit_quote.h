//Exercise 15.7: Define a class that implements a limited discount strategy,
//which applies a discount to books purchased up to a given limit. If the
//number of copies exceeds that limit, the normal price applies to those
//purchased beyond the limit.

#ifndef C__BOOK_LIMIT_QUOTE_H
#define C__BOOK_LIMIT_QUOTE_H

#include "../15.3/Quote.h"
class Limit_quote : public Quote{
public:
    Limit_quote() = default;
    Limit_quote(const std::string& book, double p,
               std::size_t qty, double disc) :
            Quote(book, p), max_qty(qty), discount(disc) { };
    double net_price(std::size_t) const override;
    void debug() override;
private:
    std::size_t max_qty = 0;
    double discount = 0.0;


};


#endif //C__BOOK_LIMIT_QUOTE_H
