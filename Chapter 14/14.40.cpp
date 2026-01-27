//Exercise 14.40: Rewrite the biggies function from § 10.3.2 (p. 391) to
//use function-object classes in place of lambdas.


#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
class isShorter
{
public:
    bool operator()(const std::string &first, const std::string &sec){return first.size() < sec.size();};
};
class isLonger
{
public:
    isLonger(int val):size(val){};
    bool operator()(const std::string &sec){return size <= sec.size();};
private:
    int size;
};

class Print
{
public:
    void operator()(std::string& data){std::cout << data << " ";}
};

void elimDups(std::vector<std::string> &vec)
{
    std::sort(vec.begin(),vec.end());
    auto endUnique = std::unique(vec.begin(),vec.end());
    vec.erase(endUnique,vec.end());
}

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(), isShorter());
    auto wc = std::find_if(words.begin(),words.end(),isLonger(sz));

    for_each(wc, words.end(),Print());
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> vecCheck = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(vecCheck,4);
    for(auto &single : vecCheck)
    {
        std::cout << single << " ";
    }
    return 0;
}

