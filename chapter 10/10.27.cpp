//Exercise 10.27: In addition to unique (§ 10.2.3, p. 384), the library
//defines function named unique_copy that takes a third iterator denoting a
//destination into which to copy the unique elements. Write a program that
//uses unique_copy to copy the unique elements from a vector into an
//initially empty list.

#include <vector>
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> intVec{1,1,2,3,4,5,5,6,7,8,9,10};
    std::list<int> intLi;
    std::unique_copy(intVec.begin(),intVec.end(),std::back_inserter(intLi));

    for(auto elem: intLi)
    {
        std::cout << elem << std::endl;
    }
    return 0;
}
