//Exercise 10.1: The algorithm header defines a function named count
//that, like find, takes a pair of iterators and a value. count returns a count
//of how often that value appears. Read a sequence of ints into a vector
//and print the count of how many elements have a given value.

#include <algorithm>
#include <vector>
#include <iostream>
#include <set>

int main()
{
    std::vector<int> vec;
    std::set<int> seen; // make sure we print each value only once
    int val;
    while(std::cin >> val)
        vec.push_back(val);
    for(auto &single : vec)
    {
        if(seen.find(single) == seen.end())
        {
            std::cout << "Value " << single << " Appears " << std::count(vec.begin(),vec.end(),single) << " times" << std::endl;
        }
        seen.insert(single);
    }
    return 0;
}