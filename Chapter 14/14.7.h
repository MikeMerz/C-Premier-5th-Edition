//Exercise 14.7: Define an output operator for you String class you wrote
//for the exercises in § 13.5 (p. 531).

#ifndef C__BOOK_14_7_H
#define C__BOOK_14_7_H
#include <memory>
class CustomString
{
public:
    friend std::ostream& operator<<(std::ostream& stream, const CustomString& obj);
    CustomString():CustomString(" "){};
    CustomString(const char*);
    CustomString(const CustomString&);

    CustomString& operator=(const CustomString&);
    ~CustomString();

    const char* c_str()const{return elements;};
    std::size_t size(){return endElem - elements;};
    std::size_t length(){return endElem - elements - 1;};

    char* begin(){return elements;};
    char* end(){return endElem;};

private:
    std::allocator<char> alloc;
    std::pair<char*,char*> alloc_n_copy(const char*,const char*);
    void free();
    char* elements;
    char* endElem;

};
std::ostream& operator<<(std::ostream& stream, const CustomString& obj);
#endif //C__BOOK_14_7_H
