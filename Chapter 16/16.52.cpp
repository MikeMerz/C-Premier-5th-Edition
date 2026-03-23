#include <iostream>
#include <string>

//Exercise 16.51: Determine what sizeof...(Args) and
//sizeof...(rest) return for each call to foo in this section.
//
//Answer:
//foo(i, s, 42, d); --> sizeof...(Args)  will return 3, sizeof...(rest) will return 3
//foo(s, 42, "hi"); --> sizeof...(Args)  will return 2, sizeof...(rest) will return 2
//foo(d, s); --> sizeof...(Args)  will return 1, sizeof...(rest) will return 1
//foo("hi"); --> sizeof...(Args)  will return 0, sizeof...(rest) will return 0
//Exercise 16.52: Write a program to check your answer to the previous
//question.
template <typename T, typename... Args>
void foo(const T &t, const Args& ... rest)
{
    std::cout << "sizeof...(Args)=" << sizeof...(Args) << std::endl;
    std::cout << "sizeof...(rest)=" << sizeof...(rest) << std::endl;
}
int main()
{
    int i = 0; double d = 3.14; std::string s = "how now brown cow";
    std::cout << "foo(i, s, 42, d):" <<std::endl;
    foo(i, s, 42, d);
    std::cout << "foo(s, 42, hi):" <<std::endl;
    foo(s, 42, "hi");
    std::cout << "foo(d, s):" <<std::endl;
    foo(d, s);
    std::cout << "foo(hi):" <<std::endl;
    foo("hi");
    return 0;
}
