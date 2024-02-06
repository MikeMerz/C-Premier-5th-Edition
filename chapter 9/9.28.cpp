//Exercise 9.28: Write a function that takes a forward_list<string> and
//two additional string arguments. The function should find the first string
//and insert the second immediately following the first. If the first string is
//not found, then insert the second string at the end of the list.

#include <forward_list>
#include <string>

void changeStrings(std::forward_list<std::string> &list, std::string &find, std::string &change)
{
    auto prev = list.before_begin();
    auto curr = list.begin();

    while(curr != list.end())
    {
        if(*curr == find)
        {
            list.insert_after(curr, change);
            return;
        }
        ++curr;
        ++prev;
    }
    list.insert_after(prev, change);
}

int main()
{
    std::forward_list<std::string> li = {"life", "is", "amazing"};
    std::string word("hi");
    std::string tochange("not");
    changeStrings(li, word, tochange);
    int x=5;
    return 0;
}
