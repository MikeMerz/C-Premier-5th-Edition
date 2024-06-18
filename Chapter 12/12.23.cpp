//Exercise 12.23: Write a program to concatenate two string literals, putting
//the result in a dynamically allocated array of char.
// Write a program to concatenate two library strings that have the same value as the literals
//used in the first program.

#include <string.h>
#include <string>
#include <iostream>

int main()
{
    const char* first = "Hello";
    const char* second = " World!";
    char* both = new char[strlen(first) + strlen(second) +1]();
    strcat(both,first);
    strcat(both,second);
    std::cout << both;

    std::string strFirst("Hello");
    std::string strSecond(" World!");
    std::cout << strFirst + strSecond;
    return 0;
}

