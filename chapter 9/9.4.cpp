//Exercise 9.4: Write a function that takes a pair of iterators to a
//vector<int> and an int value. Look for that value in the range and return
//a bool indicating whether it was found.

#include <vector>

bool wasElementFoundInRange(std::vector<int>::iterator begin, std::vector<int>::iterator end,int num)
{
    while(begin != end)
    {
        if((*begin) == num)
        {
            return true;
        }
        ++begin;
    }
    return false;
}
