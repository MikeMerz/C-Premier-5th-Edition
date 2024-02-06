//Exercise 9.27: Write a program to find and remove the odd-valued
//elements in a forward_list<int>.

#include <forward_list>
using namespace std;
void removeOdd(forward_list<int> &list)
{
    auto prev = list.before_begin();
    auto curr = list.begin();

    while(curr != list.end())
    {
        if(*curr % 2)
        {
            list.erase_after(prev);
        }
        else
        {
            prev = curr;
            ++curr;
        }
    }
}
