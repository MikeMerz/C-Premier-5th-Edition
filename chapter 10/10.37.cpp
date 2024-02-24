//Exercise 10.37: Given a vector that has ten elements, copy the elements
//from positions 3 through 7 in reverse order to a list.

#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    std::list<int> li;
    std::copy(vec.rend() - 3, vec.rbegin(),li.rbegin());

    for(auto it : li)
    {
        std::cout << it;
    }
    return 0;
}
