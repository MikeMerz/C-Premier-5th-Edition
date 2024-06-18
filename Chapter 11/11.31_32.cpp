//Exercise 11.31: Write a program that defines a multimap of authors and
//their works. Use find to find an element in the multimap and erase that
//element. Be sure your program works correctly if the element you look for is
//not in the map.

#include <map>
#include <string>
#include <set>
#include <iostream>

int main()
{
    std::multimap<std::string, std::string> authorsTitles;
    authorsTitles.insert({"Alan","Lord Of The Rings I"});
    authorsTitles.insert({"AlanA","Lord Of The Rings II"});
    authorsTitles.insert({"AlanB","Lord Of The Rings III"});

    std::string authorToDelete("Alan");
    std::string authorTitleToDelete("Lord Of The Rings II");
    auto it = authorsTitles.find(authorToDelete);
    int numberOfAlans = authorsTitles.count(authorToDelete);
    while(numberOfAlans)
    {
        if(it->second == authorTitleToDelete)
        {
            authorsTitles.erase(it);
            break;
        }
        ++it;
        --numberOfAlans;
    }

    //Exercise 11.32: Using the multimap from the previous exercise, write a
    //program to print the list of authors and their works alphabetically.
    std::map<std::string, std::multiset<std::string>> orderedTitles;
    for(auto &elem: authorsTitles)
    {
        orderedTitles[it->first].insert(it->second);
    }

    for(auto &elem : orderedTitles)
    {
        std::cout << elem.first << std::endl;
        for(auto single:elem.second)
        {
            std::cout << single << " " <<std::endl;
        }
    }
    return 0;
}
