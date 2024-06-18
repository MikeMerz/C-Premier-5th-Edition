//Exercise 11.7: Define a map for which the key is the family’s last name and
//the value is a vector of the children’s names. Write code to add new
//families and to add new children to an existing family.

#include <map>
#include <string>
#include <vector>

int main()
{
    std::map<std::string,std::vector<std::string>> families;
    families["Rozen"] = {"Amy","Michael","Daniel"};
    families["Rozen"].emplace_back("Gabriel");
    return 0;
}
