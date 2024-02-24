//Exercise 10.13: The library defines an algorithm named partition that
//takes a predicate and partitions the container so that values for which the
//predicate is true appear in the first part and those for which the predicate is
//false appear in the second part. The algorithm returns an iterator just past
//the last element for which the predicate returned true. Write a function that
//takes a string and returns a bool indicating whether the string has five
//characters or more. Use that function to partition words. Print the elements
//that have five or more characters.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

bool Dup(const std::string &str)
{
    return str.size() > 4;
}

int main()
{
    std::vector<std::string> vec{"a","aa","aaa","aaaa","aaaaa","bbbbb","ccccc"};
    auto end = std::partition(vec.begin(),vec.end(), Dup);

    for(auto it = vec.begin(); it != end;++it)
    {
        std::cout << *it << " ";
    }
    return 0;
}
