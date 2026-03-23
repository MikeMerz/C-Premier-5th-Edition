//Exercise 15.5: Define your own version of the Bulk_quote class.
//Exercise 15.26: Define the Quote and Bulk_quote copy-control members
//to do the same job as the synthesized versions. Give them and the other
//constructors print statements that identify which function is running. Write
//programs using these classes and predict what objects will be created and
//destroyed. Compare your predictions with the output and continue
//experimenting until your predictions are reliably correct.

#ifndef C__BOOK_BULK_QUOTE_H
#define C__BOOK_BULK_QUOTE_H


#include "../15.3/Quote.h"

class Bulk_quote: public Quote {
public:
    Bulk_quote* clone() const & {return new Bulk_quote(*this);}
    Bulk_quote* clone() &&
    {return new Bulk_quote(std::move(*this));}
    Bulk_quote(){std::cout << "Bulk_quote default cons is running" << std::endl;};
    Bulk_quote(const std::string& book, double p,
               std::size_t qty, double disc) :
            Quote(book, p), min_qty(qty), discount(disc) { };
    Bulk_quote(const Bulk_quote& rhs) : Quote::Quote(rhs)
    {
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        std::cout << "Bulk_quote copy constructor is running." <<std ::endl;
    }
    Bulk_quote(const Bulk_quote&& rhs) noexcept: Quote(std::move(rhs))
    {
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        std::cout << "Bulk_quote move constructor is running." << std ::endl;
    }
    Bulk_quote &operator=(const Bulk_quote &rhs)
    {
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        std::cout << "Bulk_quote operator = is running." <<std ::endl;
        return *this;
    }

    double net_price(std::size_t) const override;
    void debug() override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;

};


#endif //C__BOOK_BULK_QUOTE_H
