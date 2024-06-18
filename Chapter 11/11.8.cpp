//Exercise 11.8: Write a program that stores the excluded words in a vector
//instead of in a set. What are the advantages to using a set?
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<std::string> exclude = {"a","aa","b","bb"};
    std::string word;
    while(std::cin >> word)
    {
        if(std::find(exclude.begin(), exclude.end(),word) != exclude.end())
        {
            std::cout << "Excluded";
        }
    }
    return 0;
}
