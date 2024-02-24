//Exercise 10.18: Rewrite biggies to use partition instead of find_if.
//We described the partition algorithm in exercise 10.13 in § 10.3.1 (p.
//387).

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
    elimDups(words);

    auto wc = partition(words.begin(), words.end(),
                      [sz](const string &a)
                      { return a.size() >= sz; });

    for_each(wc, words.end(),
             [](const string &s){cout << s << " ";});
    cout << endl;
}

//Exercise 10.19: Rewrite the previous exercise to use stable_partition,
//which like stable_sort maintains the original element order in the
//paritioned sequence.


void biggiesStablePartition(vector<string> &words,
             vector<string>::size_type sz)
{
    elimDups(words);

    auto wc = stable_partition(words.begin(), words.end(),
                        [sz](const string &a)
                        { return a.size() >= sz; });

    for_each(wc, words.end(),
             [](const string &s){cout << s << " ";});
    cout << endl;
}
