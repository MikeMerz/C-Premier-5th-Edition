#include <ostream>
#include <iostream>
#include <cstring>

/*Exercise 3.39: Write a program to compare two strings. Now write a
program to compare the values of two C-style character strings.*/

int main() {
    std::string firstStr = "hello";
    std::string sectStr = "hello";

    if(firstStr == sectStr)
    {
        std::cout << "String are equal" << std::endl;
    }
    else
    {
        std::cout << "String are not equal" << std::endl;
    }

    const char* firstChar = "hello";
    const char* secChar = "hello";

    if(!strcmp(firstChar, secChar))
        std::cout << "String are equal" << std::endl;
    else
        std::cout << "String are not equal" << std::endl;
    return 0;
}