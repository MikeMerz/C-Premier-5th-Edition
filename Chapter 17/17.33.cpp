//Exercise 17.33: Write a version of the word transformation program from §
//11.3.6 (p. 440) that allows multiple transformations for a given word and
//randomly selects which transformation to apply.

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>
#include <random>

std::multimap<std::string, std::string> buildMap(std::ifstream& rules)
{
    std::multimap<std::string, std::string> trans;
    std::string key;
    std::string val;
    while(rules >> key && getline(rules,val))
    {
        if(val.size() > 1)
        {
            trans.insert({key,val.substr(1)});
        }
    }
    return trans;
}

const std::string& transform(const std::string& key, const std::multimap<std::string, std::string>& rules)
{
    static std::default_random_engine e((unsigned int)(time(0)));
    auto first = rules.lower_bound(key);
    auto last  = rules.upper_bound(key);
    auto diff = std::distance(first,last);
    auto range = rules.equal_range(key);
    std::uniform_int_distribution<unsigned> u (0, diff);
    auto iter = rules.find(key);
    std::size_t num = u(e);
    return std::next(first,num)->second;
}

void word_transform(std::ifstream& base, std::ifstream& input)
{
    std::multimap<std::string, std::string> rules = buildMap(base);

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