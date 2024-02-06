//Exercise 9.47: Write a program that finds each numeric character and then
//each alphabetic character in the string "ab2c3d7R4E6". Write two
//versions of the program. The first should use find_first_of, and the
//second find_first_not_of.

#include <string>
#include <iostream>

std::string numeric("0123456789");
std::string alpha("abcdeER");

void findNumericFirst(const std::string &str)
{
    std::cout << "All numeric numbers:" << std::endl;
    std::string::size_type pos = 0;
    while((pos=str.find_first_of(numeric,pos)) != std::string::npos)
    {
        std::cout << str[pos] << std::endl;
        ++pos;
    }

    std::cout << "All alpha numbers:" << std::endl;
    std::string::size_type pos2 = 0;
    while((pos2=str.find_first_of(alpha,pos2)) != std::string::npos)
    {
        std::cout << str[pos2] << std::endl;
        ++pos2;
    }
}
void findNumericNotOf(const std::string &str)
{
    std::cout << "All alpha numbers:" << std::endl;
    std::string::size_type pos = 0;
    while((pos=str.find_first_not_of(numeric,pos)) != std::string::npos)
    {
        std::cout << str[pos] << std::endl;
        ++pos;
    }

    std::cout << "All numeric numbers:" << std::endl;
    std::string::size_type pos2 = 0;
    while((pos2=str.find_first_not_of(alpha,pos2)) != std::string::npos)
    {
        std::cout << str[pos2] << std::endl;
        ++pos2;
    }
}
int main()
{
    findNumericFirst(std::string("ab2c3d7R4E6"));
    findNumericNotOf(std::string("ab2c3d7R4E6"));
    std::string name("r2d2");
    std::cout<< numeric.find(name);
    return 0;
}