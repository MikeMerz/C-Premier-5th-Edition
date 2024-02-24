//Exercise 10.24: Use bind and check_size to find the first element in a
//vector of ints that has a value greater than the length of a specified
//string value.

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;
bool isLargetThen(int i, const std::string &st)
{
    return i > std::stoi(st);
}

int main()
{
    std::vector<int> vec = {1,10,5,2,5,6,2,8,99,125,3,5};
    auto find = std::find_if(vec.begin(),vec.end(),std::bind(isLargetThen,_1, "4.4"));
    if(find != vec.end())
    {
        std::cout << *find;
    }
    else
    {
        std::cout << "DIDNT FIND";
    }
    return 0;
}
