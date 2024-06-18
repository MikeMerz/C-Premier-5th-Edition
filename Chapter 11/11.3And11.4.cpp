//Exercise 11.3: Write your own version of the word-counting program.

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
        ++countWords[word];
    }
}

//Exercise 11.4: Extend your program to ignore case and punctuation. For
//example, “example.” “example,” and “Example” should all increment the same
//counter.

void WordCountingWithBlacklist()
{
    std::map<std::string,int> countWords;

    std::string word;
    while(std::cin >> word)
    {
        for(auto &ch:word) { ch= tolower(ch);}
        auto removed = std::remove_if(word.begin(),word.end(), ispunct);
        word.erase(removed,word.end());
        ++countWords[word];
    }
}
