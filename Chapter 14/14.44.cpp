//Exercise 14.44: Write your own version of a simple desk calculator that can
//handle binary operations.
#include <map>
#include <string>
#include <functional>

int add(int a, int b){return a+b;}
int mult(int a, int b){return a*b;}
auto mod = [](int a, int b){return a % b;};
auto divs = [](int a, int b){return a / b;};

auto ops = std::map<std::string, std::function<int(int,int)>>
{
        {"+", add},
        {"-", std::minus<int>()},
        {"/", divs},
        {"%", mod},
        {"*", mult}
};

