//Exercise 17.24: Write your own version of the program to reformat phone
//numbers.
//Exercise 17.25: Rewrite your phone program so that it writes only the first
//phone number for each person.

#include <string>
#include <regex>
#include <iostream>
using namespace std::regex_constants;
int main()
{
    std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    std::regex r(phone);
    std::smatch m;
    std::string s;
    std::string fmt = "$2.$5.$7";
    while (getline(std::cin, s))
        std::cout << regex_replace(s, r, fmt, format_first_only) << std::endl;
    return 0;
}
