//Exercise 9.26: Using the following definition of ia, copy ia into a vector
//and into a list. Use the single-iterator form of erase to remove the
//elements with odd values from your list and the even values from your
//vector.
//int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

#include <vector>
#include <list>

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    std::vector<int> vec(std::begin(ia),std::end(ia));
    std::list<int> li(std::begin(ia),std::end(ia));

    auto liIter = li.begin();
    for(auto liIter = li.begin(); liIter != li.end();)
    {
        *liIter % 2 != 0 ? li.erase(liIter) : ++liIter;
    }
    for(auto vecIter = vec.begin();vecIter != vec.end();)
    {
        *vecIter % 2 ==0 ? vec.erase(vecIter) : ++vecIter;
    }
    return 0;
}