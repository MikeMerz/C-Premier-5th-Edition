//Exercise 9.5: Rewrite the previous program to return an iterator to the
//requested element. Note that the program must handle the case where the
//element is not found.

#include <vector>

std::vector<int>::iterator wasElementFoundInRange(std::vector<int>::iterator begin, std::vector<int>::iterator end,int num)
{
    while(begin != end)
    {
        if((*begin) == num)
        {
            return begin;
        }
        ++begin;
    }
    return end;
}
