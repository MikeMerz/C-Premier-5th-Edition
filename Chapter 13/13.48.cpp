//Exercise 13.48: Define a vector<String> and call push_back several
//times on that vector. Run your program and see how often Strings are
//copied.


#include <iostream>
#include <vector>
#include "13.49_String.h"

void foo(CustomString x)
{
    std::cout << x.c_str() << std::endl;
}

void bar(const CustomString& x)
{
    std::cout << x.c_str() << std::endl;
}

CustomString baz()
{
    CustomString ret("world");
    return ret;
}

int main()
{
    char text[] = "world";

    CustomString s0;
    CustomString s1("hello");
    CustomString s2(s0);
    CustomString s3 = s1;
    CustomString s4(text);
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temporary");
    bar("temporary");
    CustomString s5 = baz();

    std::vector<CustomString> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto &s : svec) {
        std::cout << s.c_str() << std::endl;
    }
}
