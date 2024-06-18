//Exercise 11.33: Implement your own version of the word-transformation
//program.

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <iostream>

std::map<std::string, std::string> buildMap(std::ifstream& rules)
{
    std::map<std::string, std::string> trans;
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

const std::string& transform(const std::string& key, const std::map<std::string, std::string>& rules)
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
    std::map<std::string, std::string> rules = buildMap(base);

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

int main()
{
    std::ifstream rules("rules.txt");
    std::ifstream to("Trans.txt");
    word_transform(rules,to);
    return 0;
}
