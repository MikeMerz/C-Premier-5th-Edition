//Exercise 13.17: Write versions of numbered and f corresponding to the
//previous three exercises and check whether you correctly predicted the
//output.

#include <iostream>
static int id = 1;
struct numbered
{
    numbered():mysn(id){++id;};
    numbered(const numbered& other)
    {
        mysn=id++;
    }
    int mysn;
};

void f (const numbered& s) { std::cout << s.mysn << std::endl; }

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    return 0;
}
