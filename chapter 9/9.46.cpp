//Exercise 9.46: Rewrite the previous exercise using a position and length to
//manage the strings. This time use only the insert function.

#include <string>
#include <iostream>

std::string addPrefuixSuffix(std::string &name, std::string prefix, std::string suffix)
{
    std::string ret(name.begin(),name.end());
    ret.insert(0,prefix);
    suffix = " " + suffix;
    ret.insert(ret.size(),suffix);
    return ret;
}
