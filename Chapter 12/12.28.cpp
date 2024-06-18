//Exercise 12.28: Write a program to implement text queries without defining
//classes to manage the data. Your program should take a file and interact
//with a user to query for words in that file. Use vector, map, and set
//containers to hold the data for the file and to generate the results for the
//queries.

#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <iostream>

int main()
{
    std::ifstream s("file.txt");
    std::vector<std::string> input;
    std::map<std::string, std::set<std::vector<std::string>::size_type>> dict;
    std::string line;
    decltype(input.size()) lineNumber{0};
    while(std::getline(s,line))
    {
        input.push_back(line);
        std::istringstream ss(line);
        std::string word;
        while(ss >> word)
        {
            dict[word].insert(lineNumber);
        }
        ++lineNumber;
    }

    while(true)
    {
        std::cout << "Please Enter word for search:";
        std::string search;
        if(!(std::cin >> search) || search == "stop")
            break;
        auto iter = dict.find(search);
        if(iter != dict.end())
        {
            std::cout << search << " occurs " << iter->second.size() << " times " << std::endl;
        }
        else
        {
            std::cout << search << " occurs 0 times " << std::endl;
        }

    }
    return 0;
}
