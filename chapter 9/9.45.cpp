//Exercise 9.45: Write a funtion that takes a string representing a name
//and two other strings representing a prefix, such as “Mr.” or “Ms.” and a
//suffix, such as “Jr.” or “III”. Using iterators and the insert and append
//functions, generate and return a new string with the suffix and prefix
//added to the given name.

#include <string>
#include <iostream>

std::string addPrefuixSuffix(std::string &name, std::string prefix, std::string suffix)
{
    std::string ret(name.begin(),name.end());
    ret.insert(ret.begin(),prefix.begin(),prefix.end());
    suffix = " " + suffix;
    ret.append(suffix);
    return ret;
}
int main()
{
    std::string orig("Michael");
    auto k =addPrefuixSuffix(orig,"Mr.", "III");
    std::cout<<k;
    return 0;
}