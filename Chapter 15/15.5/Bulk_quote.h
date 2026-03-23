#ifndef C__BOOK_BULK_QUOTE_H
#define C__BOOK_BULK_QUOTE_H


#include <string>
#include "Disc_quote.h"

class Bulk_quote: public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p,
               std::size_t qty, double disc) :
            Disc_quote(book, p,qty, disc) { };
    double net_price(std::size_t) const override;

};


#endif //C__BOOK_BULK_QUOTE_H
