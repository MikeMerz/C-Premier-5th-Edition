//Exercise 10.29: Write a program using stream iterators to read a text file
//into a vector of strings.

#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <iostream>

int main()
{
    std::ifstream in("10.29_Strings");
    std::vector<std::string> vec;
    std::istream_iterator<std::string> inputIter(in);
    std::istream_iterator<std::string> end;

    if(in)
    {
        for(auto it = inputIter; it != end; ++it)
        {
            vec.push_back(*it);
        }
    }

    for(auto elem : vec)
    {
        std::cout<< elem;
    }
    return 0;
}