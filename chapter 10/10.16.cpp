//Exercise 10.16: Write your own version of the biggies function using lambdas.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
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

void biggies(vector<string> &words,
             vector<string>::size_type sz)
{
    elimDups(words); // put words in alphabetical order and remove duplicates
// sort words by size, but maintain alphabetical order for words of the same size
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                { return a.size() < b.size();});
// get an iterator to the first element whose size() is >= sz
    auto wc = find_if(words.begin(), words.end(),
                      [sz](const string &a)
                      { return a.size() >= sz; });

// print words of the given size or longer, each one followed by a space
    for_each(wc, words.end(),
             [](const string &s){cout << s << " ";});
    cout << endl;
}
int main(){
    return 0;
}
