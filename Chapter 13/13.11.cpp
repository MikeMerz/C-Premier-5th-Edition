//Exercise 13.11: Add a destructor to your HasPtr class from the previous
//exercises.

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& other):ps(new std::string(*other.ps)),i(other.i){}
    HasPtr& operator=(const HasPtr& other){
        if( &other == this)
            return *this;
        delete ps;
        ps = new std::string(*other.ps);
        i = other.i;
        return *this;
    }
    ~HasPtr(){delete ps;}
private:
    std::string *ps;
    int i;
};
