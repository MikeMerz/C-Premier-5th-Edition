//Exercise 17.27: Write a program that reformats a nine-digit zip code as
//ddddd-dddd.
#include <string>
#include <regex>
#include <iostream>
int main()
{
    std::string phone = "^\\d{5}(-?\\d{4})?$";
    std::regex r(phone);
    std::smatch m;
    std::string s;
    std::string fmt = "$2-$3";
    while (getline(std::cin, s))
        std::cout << regex_replace(s, r, fmt) << std::endl;
    return 0;
}