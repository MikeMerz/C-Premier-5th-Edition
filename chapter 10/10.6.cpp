//Exercise 10.6: Using fill_n, write a program to set a sequence of int
//values to 0.

#include <vector>
#include <algorithm>
int main()
{
    std::vector<int> vec;
    vec.reserve(10);
    std::fill_n(vec.begin(), 10, 0);
    return 0;
}
