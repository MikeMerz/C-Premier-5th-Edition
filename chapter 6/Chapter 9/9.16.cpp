//Exercise 9.16: Repeat the previous program, but compare elements in a
//list<int> to a vector<int>.

#include <vector>
#include <list>

bool isListEqualToVec(std::vector<int> &vec, std::list<int> &list)
{
    auto vecIter = vec.begin();
    auto listIter = list.begin();
    while(vecIter != vec.end() && listIter != list.end())
    {
        if(*vecIter != *listIter)
        {
            return false;
        }
    }
    return (vecIter == vec.end() && listIter== list.end());
}
