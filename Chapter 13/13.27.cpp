//Exercise 13.27: Define your own reference-counted version of HasPtr.

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0),ref(new std::size_t(1)) { }
    HasPtr(const HasPtr& other):ps(new std::string(*other.ps)),i(other.i),ref(other.ref){++*ref;}
    HasPtr& operator=(const HasPtr& other){
        ++*(other.ref);
        if(--*ref == 0)
        {
            delete ps;
            delete ref;
        }
        ps = other.ps;
        i = other.i;
        ref = other.ref;
        return *this;
    }
    ~HasPtr(){
        if(--*ref == 0)
        {
            delete ps;
            delete ref;
        }
    }
private:
    std::string *ps;
    int i;
    std::size_t *ref;
};
