//Exercise 10.42: Reimplement the program that eliminated duplicate words
//that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.


#include <list>
#include <string>

int main()
{
    std::list<std::string> vec{"hi","come","back"};
    vec.sort();

    vec.unique();

    return 0;
}
