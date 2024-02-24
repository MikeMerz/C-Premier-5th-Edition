//Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive,
//into three other containers. Use an inserter, a back_inserter, and a
//front_inserter, respectivly to add elements to these containers. Predict
//how the output sequence varies by the kind of inserter and verify your
//predictions by running your programs.

#include <iterator>
#include <vector>
#include <forward_list>
#include <list>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> vec{1,2,3,4,5,6,7,8,9};

    std::list<int> BackInserter;
    std::list<int> frontInserter;
    std::list<int> liInserter;

    std::copy(vec.begin(),vec.end(),std::front_inserter(frontInserter));
    //The output will be : 9,8,7,6,5,4,3,2,1
    for(auto i : frontInserter)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::copy(vec.begin(),vec.end(),std::back_inserter(BackInserter));
    //The output will be : 1,2,3,4,5,6,7,8,9
    for(auto i : BackInserter)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::copy(vec.begin(),vec.end(),std::inserter(liInserter,liInserter.begin()));
    //The output will be : 1,2,3,4,5,6,7,8,9
    for(auto i : liInserter)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
