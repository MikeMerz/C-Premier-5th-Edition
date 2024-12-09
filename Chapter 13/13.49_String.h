//Exercise 13.49: Add a move constructor and move-assignment operator to
//your StrVec, String, and Message classes.

#include <memory>
class CustomString
{
public:
    CustomString():CustomString(" "){};
    CustomString(const char*);
    CustomString(const CustomString&);
    CustomString(CustomString&&) noexcept;

    CustomString& operator=(const CustomString&);
    CustomString& operator=(CustomString&&);
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