//Exercise 13.8: Write the assignment operator for the HasPtr class from
//exercise 13.5 in § 13.1.1 (p. 499). As with the copy constructor, your
//assignment operator should copy the object to which ps points.

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
private:
    std::string *ps;
    int i;
};
