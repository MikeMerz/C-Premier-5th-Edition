//Exercise 16.19: Write a function that takes a reference to a container and
//prints the elements in that container. Use the container’s size_type and
//size members to control the loop that prints the elements.
//Exercise 16.20: Rewrite the function from the previous exercise to use
//iterators returned from begin and end to control the loop.

#include <iostream>
#include <vector>

template<typename T>
void print(T& con)
{
    for(typename T::size_type i = 0; i < con.size();++i)
    {
        std::cout << con[i] << std::endl;
    }
}
template<typename T>
void printUsingIters(T& container)
{
    for(auto iter = std::begin(container); iter != std::end(container); ++iter)
    {
        std::cout << *iter << std::endl;
    }
}
int main()
{
    std::vector<int> v1{1,2,3,4,5,6,7};
    std::vector<std::string> v2{"a","aa","aaa"};

    print(v1);
    print(v2);

    printUsingIters(v1);
    printUsingIters(v2);
    return 0;
}