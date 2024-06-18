//Exercise 11.38: Rewrite the word-counting (§ 11.1, p. 421) and wordtransformation
//(§ 11.3.6, p. 440) programs to use an unordered_map.

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <iostream>

std::unordered_map<std::string, std::string> buildMap(std::ifstream& rules)
{
    std::unordered_map<std::string, std::string> trans;
    std::string key;
    std::string val;
    while(rules >> key && getline(rules,val))
    {
        if(val.size() > 1)
        {
            trans[key]=val.substr(1);
        }
    }
    return trans;
}

const std::string& transform(const std::string& key, const std::unordered_map<std::string, std::string>& rules)
{
    auto iter = rules.find(key);
    if(iter != rules.end())
    {
        return iter->second;
    }
    return key;
}

void word_transform(std::ifstream& base, std::ifstream& input)
{
    std::unordered_map<std::string, std::string> rules = buildMap(base);

    std::string txt;
    while(getline(input,txt))
    {
        std::istringstream stream(txt);
        std::string word;
        bool isFirst = true;
        while(stream >> word)
        {
            if(isFirst)
            {
                isFirst = false;
            }
            else
            {
                std::cout << " ";
            }
            std::cout << transform(word,rules);
        }
        std::cout << std::endl;
    }
}
void countWords()
{
    std::unordered_map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word)
        ++word_count[word];
    for (const auto &w : word_count)
        std::cout << w.first << " occurs " << w.second
             << ((w.second > 1) ? " times" : " time") << std::endl;
}


