//Exercise 10.25: In the exercises for § 10.3.2 (p. 392) you wrote a version
//of biggies that uses partition. Rewrite that function to use
//check_size and bind.


#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;
using namespace std;

void elimDups(std::vector<std::string> &vec)
{
    std::sort(vec.begin(),vec.end());

    auto endUnique = std::unique(vec.begin(),vec.end());

    vec.erase(endUnique,vec.end());

}

bool isLongerThan(const std::string &st, int size)
{
    return st.size() > size;
}

int main()
{
    std::vector<std::string> vec = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(vec);

    auto wc = partition(vec.begin(), vec.end(),
                        std::bind(isLongerThan, _1, 4));

    for_each(wc, vec.end(),
             [](const string &s){cout << s << " ";});
    cout << endl;
    return 0;
}
