//Exercise 10.3: Use accumulate to sum the elements in a vector<int>.

#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>

int main()
{
    std::vector<int> vec = {10,2,3,4,5,6,2,1,3,4,5,6,8,10};
    std::cout << "Sum is: " << std::accumulate(vec.cbegin(), vec.cend(), 0);
    return 0;
}