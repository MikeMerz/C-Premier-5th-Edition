//Exercise 10.34: Use reverse_iterators to print a vector in reverse
//order.

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <list>

void printReverseIterator()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    std::ostream_iterator<int> out(std::cout," ");
    std::copy(vec.rbegin(),vec.rend(),out);
}

//Exercise 10.35: Now print the elements in reverse order using ordinary iterators.
void printReverseOrdinaryIter()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    for(auto end = --vec.end(); end != vec.begin();--end)
    {
        std::cout << *end << " ";
    }
    std::cout << *(vec.begin()) << " ";
}

//Exercise 10.36: Use find to find the last element in a list of ints with
//value 0.

void findLastZero()
{
    std::list<int> li{1,2,3,0,4,5,6,7,8,9,10,0};
    auto found = std::find(li.crbegin(),li.crend(),0);
    std::cout << "index is: " << std::distance(found,li.crend());
}


//Exercise 10.37: Given a vector that has ten elements, copy the elements
//from positions 3 through 7 in reverse order to a list.

void copyInReverse()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    std::list<int> li;
    std::copy(vec.begin() + 3,vec.end() - 2,std::front_inserter(li));
}
int main()
{
    printReverseIterator();
    printReverseOrdinaryIter();
    findLastZero();
    copyInReverse();
    return 0;
}