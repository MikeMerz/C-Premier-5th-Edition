#ifndef C__BOOK_LIMIT_QUOTE_H
#define C__BOOK_LIMIT_QUOTE_H

#include "Disc_quote.h"
class Limit_quote : public Disc_quote{
public:
    Limit_quote() = default;
    Limit_quote(const std::string& book, double p,
                std::size_t qty, double disc) :
            Disc_quote(book, p,qty, disc) { };
    double net_price(std::size_t) const override;
    void debug() override;
};


#endif //C__BOOK_LIMIT_QUOTE_H
