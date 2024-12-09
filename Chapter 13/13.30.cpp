//Exercise 13.30: Write and test a swap function for your valuelike version of
//HasPtr. Give your swap a print statement that notes when it is executed.

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

class HasPtr {
public:
    friend void swap(HasPtr& lhs, HasPtr& rhs);
    friend bool operator<(const HasPtr& lhs, const HasPtr& rhs);
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& other):ps(new std::string(*other.ps)),i(other.i){}
    HasPtr& operator=(const HasPtr& other){
        auto newp = new std::string(*other.ps);
        delete ps;
        ps = newp;
        i = other.i;
        return *this;
    }
    ~HasPtr(){delete ps;}
private:
    std::string *ps;
    int i;
};
inline void swap(HasPtr& lhs, HasPtr& rhs)
{
    std::cout << "Swapping " << *(lhs.ps) << " with " << *(rhs.ps) << std::endl;
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
    std::cout << "Swapped " << *(lhs.ps) << "with " << *(rhs.ps) << std::endl;
}
bool operator<(const HasPtr& lhs,const HasPtr& rhs)
{
    return *(lhs.ps) < *(rhs.ps);
}
int main()
{
//    HasPtr s1("Hello");
//    HasPtr s2("World");
//    swap(s1,s2);
    //Exercise 13.31: Give your class a < operator and define a vector of
    //HasPtrs. Give that vector some elements and then sort the vector. Note when swap is called.
    HasPtr b{"s"},a{"a"},c{"b"};
    std::vector<HasPtr> vector1{b,a,c};
    std::sort(vector1.begin(),vector1.end());
    return 0;
}

