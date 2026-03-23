//Exercise 15.3: Define your own versions of the Quote class and the
//print_total function.
//Exercise 15.11: Add a virtual debug function to your Quote class hierarchy
//that displays the data members of the respective classes.
//Exercise 15.26: Define the Quote and Bulk_quote copy-control members
//to do the same job as the synthesized versions. Give them and the other
//constructors print statements that identify which function is running. Write
//programs using these classes and predict what objects will be created and
//destroyed. Compare your predictions with the output and continue
//experimenting until your predictions are reliably correct.

#include <string>
#include <iostream>
class Quote {
public:
    Quote(){std::cout << "Quote default const is running"<<std::endl;};
    Quote(const std::string &book, double sales_price):bookNo(book),price(sales_price){};
    std::string isbn() const {return bookNo;}
    Quote(const Quote &rhs):bookNo(rhs.bookNo),price(rhs.price){std::cout << " Quote Copy const is running"<<std::endl;}
    Quote(const Quote &&rhs) noexcept:bookNo(rhs.bookNo),price(rhs.price){std::cout << " Quote Move const is running"<<std::endl;}
    Quote &operator=(const Quote &rhs){
        bookNo = rhs.bookNo;
        price = rhs.price;
        std::cout << " Quote operator= is running"<<std::endl;
        return *this;
    }
    virtual Quote* clone() const & {return new Quote(*this);};
    virtual Quote* clone() && {return new Quote(std::move(*this));}
    virtual double net_price(std::size_t n) const {return n * price;}
    double print_total(std::ostream& os, const Quote &item, std::size_t n);
    virtual void debug();
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;

};
