//Exercise 13.58: Write versions of class Foo with print statements in their
//sorted functions to test your answers to the previous two exercises.

#include <vector>
#include <algorithm>
#include <iostream>

class Foo
{
public:
    Foo sorted() &&;
    Foo sorted() const &;
private:
    std::vector<int> data;
};

Foo Foo::sorted() &&
{
    std::sort(data.begin(),data.end());
    std::cout << "sorted && was called" << std::endl;
    return *this;
}

Foo Foo::sorted() const &
{
    //13.56
    //Foo ret(*this);
    //return ret.sorted();

    //13.57
    return Foo(*this).sorted();
}




int main()
{
    Foo().sorted();
    Foo f;
    f.sorted();
    return 0;
}
