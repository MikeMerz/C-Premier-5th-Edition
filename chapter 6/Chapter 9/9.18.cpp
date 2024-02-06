//Exercise 9.18: Write a program to read a sequence of strings from the
//standard input into a deque. Use iterators to write a loop to print the
//elements in the deque.

#include <deque>
#include <string>
#include <iostream>

int main()
{
    std::deque<std::string> de;
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
