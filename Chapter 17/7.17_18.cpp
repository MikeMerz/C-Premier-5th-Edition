//Exercise 17.17: Update your program so that it finds all the words in an
//input sequence that violiate the “ei” grammar rule.
//Exercise 17.18: Revise your program to ignore words that contain “ei” but
//are not misspellings, such as “albeit” and “neighbor.”
#include <regex>
#include <iostream>


using namespace std;
int main()
{
    string s;
    std::cout << "Please input a word, enter q to quit" << endl;
    getline(std::cin, s);
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    std::regex r(pattern, regex::icase);
    for(sregex_iterator it(s.begin(),s.end(),r),end_it; it != end_it; ++it)
    {
        std::cout << it->str() << std::endl;
    }
    return 0;
}