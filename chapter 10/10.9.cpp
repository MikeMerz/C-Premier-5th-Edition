//Exercise 10.9: Implement your own version of elimDups. Test your
//program by printing the vector after you read the input, after the call to
//unique, and after the call to erase.

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
    return 0;
}