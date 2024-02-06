//Exercise 9.41: Write a program that initializes a string from a
//vector<char>.

#include <vector>
#include <string>

int main()
{
    std::vector<char> vec = {'h', 'i', 'I', 'a', 'm', 'h', 'o', 'm', 'e'};
    std::string vecAsString(vec.begin(),vec.end());
    return 0;
}
