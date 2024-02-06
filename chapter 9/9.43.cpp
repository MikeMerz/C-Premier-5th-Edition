//Exercise 9.43: Write a function that takes three strings, s, oldVal, and
//newVal. Using iterators, and the insert and erase functions replace all
//instances of oldVal that appear in s by newVal. Test your function by
//using it to replace common abbreviations, such as “tho” by “though” and
//“thru” by “through”.

#include <string>
#include <iostream>
#include <algorithm>

std::string replaceAll(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    for(auto iter = s.begin(); iter < s.end() - oldVal.size() + 1;)
    {
        if(*iter == oldVal[0])
        {
            if(std::equal(iter,iter+oldVal.size(),oldVal.begin(),oldVal.end()))
            {
                auto pos = iter-s.begin();
                s.erase(iter, iter + oldVal.size());
                s.insert(pos, newVal,0, newVal.size());
                iter = s.begin() + pos + newVal.size() - 1; //we add the -1 in case that the newVal will cause another match
                continue;
            }
        }
            ++iter;
    }
    return s;
}

int main()
{
    std::string orig("aaaa");
    replaceAll(orig,"aa", "a");
    std::cout<<orig;
    return 0;
}
