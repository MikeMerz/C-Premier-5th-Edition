//Exercise 11.20: Rewrite the word-counting program from § 11.1 (p. 421) to
//use insert instead of subscripting. Which program do you think is easier to
//write and read? Explain your reasoning.

#include <map>
#include <string>
#include <algorithm>
#include <iostream>

void WordCounting()
{
    std::map<std::string,int> countWords;

    std::string word;
    while(std::cin >> word)
    {
        auto it = countWords.insert({word,1});
        if(!it.second)
            ++(it.first->second);
    }
}
//I think the subscripting is the easier way since using insert is much less readable.