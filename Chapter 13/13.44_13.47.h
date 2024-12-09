//Exercise 13.44: Write a class named String that is a simplified version of
//the library string class. Your class should have at least a default
//constructor and a constructor that takes a pointer to a C-style string. Use an
//allocator to allocate memory that your String class uses.

//Exercise 13.47: Give the copy constructor and copy-assignment operator in
//your String class from exercise 13.44 in § 13.5 (p. 531) a statement that
//prints a message each time the function is executed.

#include <memory>
class CustomString
{
public:
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