//Exercise 16.47: Write your own version of the flip function and test it by
//calling functions that have lvalue and rvalue reference parameters.
#include <utility>
#include <string>
#include <iostream>

void lvalueFunc(std::string& lhs, std::string& rhs)
{
    std::cout <<" IM AT THE LVALUE ONEEE" <<"lhs=" <<lhs<<"rhs="<<rhs<<std::endl;
}
void rvalueFunc(std::string&& lhs, std::string&& rhs)
{
    std::cout <<" IM AT THE RVALUE ONEEE" <<"lhs=" <<lhs<<"rhs="<<rhs<<std::endl;
}
template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
    std::string a("a"),b("b");
    flip(lvalueFunc,a,b);
    std::cout <<" I WAS THE LVALUE ONEEE" <<"lhs=" <<a<<"rhs="<<b<<std::endl;
    flip(rvalueFunc,"a","b");
    return 0;
}
