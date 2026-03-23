//Exercise 16.2: Write and test your own versions of the compare functions.
//Exercise 16.3: Call your compare function on two Sales_data objects to
//see how your compiler handles errors during instantiation.
//error: no match for 'operator<' (operand types are 'const Sales_data' and
//  'const Sales_data')
#include <vector>
#include <iostream>

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    if (lhs < rhs) return -1;
    if (rhs < lhs) return 1;
    return 0;
}
int main()
{
    auto intCompare = compare(1,2);
    std::cout << intCompare <<std::endl;
    std::vector first{1,2,3};
    std::vector second{4,5,6};
    auto vecComp = compare(first,second);
    std::cout << vecComp <<std::endl;
    return 0;
}