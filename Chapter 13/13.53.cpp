//Exercise 13.53: As a matter of low-level efficiency, the HasPtr assignment
//operator is not ideal. Explain why. Implement a copy-assignment and moveassignment
//operator for HasPtr and compare the operations executed in
//your new move-assignment operator versus the copy-and-swap version.

//Answer:
//When using swap there are more copies being made, one copy from hp2 to rhs and one copy from rhs to this.
//for refrence https://stackoverflow.com/questions/21010371/why-is-it-not-efficient-to-use-a-single-assignment-operator-handling-both-copy-a

#include <string>
#include <iostream>

class HasPtr {
    friend void swap(HasPtr lhs, HasPtr rhs);
public:
    HasPtr(const std::string &s = std::string()):ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& other):ps(new std::string(*other.ps)),i(other.i){}
    HasPtr(HasPtr&& other) noexcept :ps(other.ps),i(other.i){other.ps = nullptr;i=0;}
    HasPtr& operator=(HasPtr rhs)
    { swap(*this, rhs); return *this; }
    ~HasPtr(){delete ps;}
private:
    std::string *ps;
    int i;
};

void swap(HasPtr lhs, HasPtr rhs) {
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    std::cout << "called SWAP"<< std::endl;
}
