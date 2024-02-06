//Exercise 9.38: Write a program to explore how vectors grow in the library
//you use.

#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;
    for(int i = 0; i < 100; ++i)
    {
        std::cout << "Vector size is: " << vec.size() << std::endl;
        std::cout << "Vector capacity is: " <<vec.capacity() << std::endl;
        vec.push_back(i);
    }
    return 0;
}
