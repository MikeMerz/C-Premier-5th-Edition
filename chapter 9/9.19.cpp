//Exercise 9.19: Rewrite the program from the previous exercise to use a
//list. List the changes you needed to make.


#include <list>
#include <string>
#include <iostream>

int main()
{
    std::list<std::string> de;
    std::string word;
    while(std::cin >> word)
    {
        if(word == "stop")
            break;
        de.push_back(word);
    }
    auto deIter = de.begin();
    while(deIter != de.end())
    {
        std::cout << (*deIter) << std::endl;
        ++deIter;
    }
    return 0;
}

