//Exercise 10.20: The library defines an algorithm named count_if. Like
//find_if, this function takes a pair of iterators denoting an input range and
//a predicate that it applies to each element in the given range. count_if
//returns a count of how often the predicate is true. Use count_if to rewrite
//the portion of our program that counted how many words are greater than
//length 6.

#include <vector>
#include <string>
#include <algorithm>

size_t countOfStringsLonerThan(std::vector<std::string> &vec, int size)
{
    return std::count_if(vec.begin(),vec.end(),[&size](const std::string &st)->bool{
        return st.size() > size;
    });
}

//Exercise 10.21: Write a lambda that captures a local int variable and
//decrements that variable until it reaches 0. Once the variable is 0 additional
//calls should no longer decrement the variable. The lambda should return a
//bool that indicates whether the captured variable is 0.

void decrementToZero()
{
    int i = 42;
    auto lambda = [&i](){
        return i > 0 ? !(--i) : !i;
    };
}
