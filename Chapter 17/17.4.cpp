//Exercise 17.4: Write and test your own version of the findBook function.
//Exercise 17.5: Rewrite findBook to return a pair that holds an index and
//a pair of iterators.
//Exercise 17.6: Rewrite findBook so that it does not use tuple or pair.
//Exercise 17.7: Explain which version of findBook you prefer and why.
//Answer:
//The tuple version is preferable since it's more flexible and easier to understand.
//Exercise 17.8: What would happen if we passed Sales_data() as the
//third parameter to accumulate in the last code example in this section?
//Answer:
//The output will be 0 since Sales_data() will call the default constructor and we will just sum the default value each time.

#include <vector>
#include <algorithm>
#include <bitset>
#include "../7.26.h"

using namespace std;
typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;
//ex 17.5
typedef tuple<pair<vector<Sales_data>::size_type,pair<vector<Sales_data>::const_iterator,vector<Sales_data>::const_iterator>>> matches_pair;
//ex 17.6
struct matches_data
{
    vector<Sales_data>::size_type vecSize;
    vector<Sales_data>::const_iterator first;
    vector<Sales_data>::const_iterator last;
};
//ex 17.6
//vector<matches> findbook(const vector<vector<Sales_data>> &files, const string &book)
//{
//    vector<matches> ret;
//    for(auto it = files.cbegin(); it != files.cend(); ++it)
//    {
//        auto found = equal_range(it->cbegin(),it->cend(),book, compareIsbn);
//        if(found.first != found.second)
//        {
//            ret.push_back({it - files.cbegin(),found.first,found.second});
//        }
//    }
//    return ret;
//}
vector<matches> findbook(const vector<vector<Sales_data>> &files, const string &book)
{
    vector<matches> ret;
    for(auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = equal_range(it->cbegin(),it->cend(),book, compareIsbn);
        if(found.first != found.second)
        {
            ret.push_back(make_tuple(it - files.cbegin(),found.first,found.second));
        }
    }
    return ret;
}
int main()
{
    return 0;
}