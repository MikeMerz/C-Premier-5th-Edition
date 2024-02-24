//Exercise 10.2: Repeat the previous program, but read values into a list of
//strings.

#include <algorithm>
#include <list>
#include <string>
#include <iostream>
#include <set>

int main()
{
    std::list<std::string> li;
    std::string val;
    std::set<std::string> seen; // make sure we print each value only once
    while(std::cin >> val)
    {
        if(val == "STOP")
            break;
        li.push_back(val);
    }
    for(auto &single : li)
    {
        if(seen.find(single) == seen.end())
        {
            std::cout << "Value " << single << " Appears " << std::count(li.begin(),li.end(),single) << " times" << std::endl;
        }
        seen.insert(single);
    }
    return 0;
}
