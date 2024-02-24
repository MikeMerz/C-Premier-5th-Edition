//Exercise 10.30: Use stream iterators, sort, and copy to read a sequence
//of integers from the standard input, sort them, and then write them back to
//the standard output.


#include <iterator>
#include <algorithm>
#include <iostream>
#include <vector>

int TenThirty()
{
    std::istream_iterator<int> in(std::cin);
    std::istream_iterator<int> end;
    std::vector<int> vec(in,end);
    std::sort(vec.begin(), vec.end());
    std::copy(vec.begin(),vec.end(),std::ostream_iterator<int>(std::cout," "));
    return 0;
}

//Exercise 10.31: Update the program from the previous exercise so that it
//prints only the unique elements. Your program should use unqiue_copy (§
//10.4.1, p. 403).

int TenThirtyOne()
{
    std::istream_iterator<int> in(std::cin);
    std::istream_iterator<int> end;
    std::vector<int> vec(in,end);
    std::sort(vec.begin(), vec.end());
    std::unique_copy(vec.begin(),vec.end(),std::ostream_iterator<int>(std::cout," "));
    return 0;
}


