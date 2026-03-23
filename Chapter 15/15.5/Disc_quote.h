#ifndef C__BOOK_DISC_QUOTE_H
#define C__BOOK_DISC_QUOTE_H

//Exercise 15.15: Define your own versions of Disc_quote and
//Bulk_quote.
//Exercise 15.16: Rewrite the class representing a limited discount strategy,
//which you wrote for the exercises in § 15.2.2 (p. 601), to inherit from
//Disc_quote.
//Exercise 15.17: Try to define an object of type Disc_quote and see what
//errors you get from the compiler. - 'Disc_quote' : cannot instantiate abstract class
#include "../15.3/Quote.h"

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string  &book, double price, std::size_t qty, double disc):Quote(book, price),quantity(qty), discount(disc){};
    virtual double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};


#endif //C__BOOK_DISC_QUOTE_H
