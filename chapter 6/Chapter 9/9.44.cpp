//Exercise 9.44: Rewrite the previous function using an index and replace.

#include <string>
#include <iostream>

std::string replaceAll(std::string &s, const std::string &oldVal, const std::string &newVal)
{
    for(int i = 0; i < s.size() - oldVal.size() + 1;++i)
    {
        if(s[i] == oldVal[0])
        {
            int j=1;
            for(;j<oldVal.size();++j)
            {
                if(s[i+j] != oldVal[j]){break;}
            }
            if(j == oldVal.size())
            {
                s.replace(i,j,newVal);
                i-=1;
            }
        }
    }
    return s;
}
int main()
{
    std::string orig("abaa");
    replaceAll(orig,"aa", "a");
    std::cout<<orig;
    return 0;
}