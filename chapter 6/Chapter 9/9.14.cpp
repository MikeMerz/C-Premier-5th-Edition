//Exercise 9.14: Write a program to assign the elements from a list of
//char* pointers to C-style character strings to a vector of strings.

#include <list>
#include <string>
#include <vector>

std::vector<std::string> fromListToVector(std::list<const char*> list)
{
    std::vector<std::string> vec;
    vec.assign(list.begin(),list.end());
    return vec;
}
int main()
{
    std::list<const char*> list = {"hello","hi","bye"};
    std::vector<std::string> vechi = fromListToVector(list);
    return 0;
}
