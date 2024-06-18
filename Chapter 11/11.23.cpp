//Exercise 11.23: Rewrite the map that stored vectors of children’s names
//with a key that is the family last name for the exercises in § 11.2.1 (p. 424)
//to use a multimap.

#include <map>
#include <string>
#include <vector>

int main() {
    std::multimap<std::string, std::string> families;
    families.insert({"Rozen","Amy"});
    families.emplace("Rozen","hello");
    families.insert({"Rozen","Michael"});
    families.insert({"Rozen","kaka"});
    return 0;
}
