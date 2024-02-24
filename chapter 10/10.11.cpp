//Exercise 10.11: Write a program that uses stable_sort and isShorter
//to sort a vector passed to your version of elimDups. Print the vector to
//verify that your program is correct.

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

void elimDups(std::vector<std::string> &vec)
{
    std::sort(vec.begin(),vec.end());

    for(auto &single : vec)
    {
        std::cout << single << " ";
    }
    std::cout << std::endl;
    auto endUnique = std::unique(vec.begin(),vec.end());

    for(auto &single : vec)
    {
        std::cout << single << " ";
    }

    vec.erase(endUnique,vec.end());

    for(auto &single : vec)
    {
        std::cout << single << " ";
    }
}

int main()
{
    std::vector<std::string> vecCheck = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vecCheck);

    std::stable_sort(vecCheck.begin(),vecCheck.end(),[](const std::string &first, const std::string &sec)
    {
        return first.size() < sec.size();
    });

    for(auto &single : vecCheck)
    {
        std::cout << single << " ";
    }
    return 0;
}

