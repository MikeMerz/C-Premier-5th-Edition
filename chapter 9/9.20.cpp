//Exercise 9.20: Write a program to copy elements from a list<int> into
//two deques. The even-valued elements should go into one deque and the
//odd ones into the other.

#include <list>
#include <deque>

void ConvertListToDequqes(const std::list<int> &list)
{
    std::deque<int> de1,de2;
    for(auto iter : list)
    {
        iter % 2 ==0 ? de1.push_back(iter) : de2.push_back(iter);
    }
}
