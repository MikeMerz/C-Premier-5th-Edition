//Exercise 14.5: In exercise 7.40 from § 7.5.1 (p. 291) you wrote a sketch of
//one of the following classes. Decide what, if any, overloaded operators your
//class should provide.
//(a) Book
//(b) Date
//(c) Employee
//(d) Vehicle
//(e) Object
//(f) Tree

//Exercise 14.8: Define an output operator for the class you chose in exercise
//7.40 from § 7.5.1 (p. 291).

//Exercise 14.12: Define an input operator for the class you used in exercise
//7.40 from § 7.5.1 (p. 291). Be sure the operator handles input errors.

//Exercise 14.17: Should the class you chose for exercise 7.40 from § 7.5.1
//(p. 291) define the equality operators? If so, implement them. If not, explain
//why not.
//Exercise 14.24: Decide whether the class you used in exercise 7.40 from §
//7.5.1 (p. 291) needs a copy- and move-assignment operator. If so, define
//those operators.
//Exercise 14.25: Implement any other assignment operators your class
//should define. Explain which types should be used as operands and why.
//Exercise 14.49: Regardless of whether it is a good idea to do so, define a
//conversion to bool for the class from the previous exercise.

#include <string>

class Book
{
    friend bool operator==(const Book& lhs, const Book& rhs);
    friend bool operator!=(const Book& lhs, const Book& rhs);
    friend std::ostream& operator<<(std::ostream& stream, const Book& obj);
    friend std::istream& operator>>(std::istream& stream, Book& obj);
public:
    Book() = default;
    Book(const std::string t, const std::string &au, const std::string & puCompany,int year, double p):
            title(t), author(au), publishCompany(puCompany), publishYear(year), price(p){};
    //operator bool(){return } **FINISH ME***

private:
    std::string title;
    std::string author;
    std::string publishCompany;
    int publishYear;
    double price;

};

bool operator==(const Book& lhs, const Book& rhs);
bool operator!=(const Book& lhs, const Book& rhs);
std::ostream& operator<<(std::ostream& stream, const Book& obj);
std::istream& operator>>(std::istream& stream, const Book& obj);