//Exercise 10.22: Rewrite the program to count words of size 6 or less using
//functions in place of the lambdas.

#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std::placeholders;

bool isLongerThan(const std::string &st, int size)
{
    return st.size() > size;
}

size_t countOfStringsLonerThan(std::vector<std::string> &vec, int size)
{
    auto callable = std::bind(isLongerThan,_1,size);
    return std::count_if(vec.begin(),vec.end(),std::bind(isLongerThan,_1,6));
}
