#include <string>
#include <vector>
#include <iostream>
#include <sstream>

//Exercise 8.11: The program in this section defined its istringstream
//object inside the outer while loop. What changes would you need to make if
//record were defined outside that loop? Rewrite the program, moving the
//definition of record outside the while, and see whether you thought of all
//the changes that are needed.

/*
 * Answer:
 * When inside the loop the istringstream gets destroyed each itearion and thus is cleared, moving it outside the while loop will cause it
 * to push back only the first person since record will encounter end of file and won't read the other data, so we will need to call clear each iteration.
 */
struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::vector<PersonInfo> people;
    std::string line, word;

    std::istringstream record(line);

    while (getline(std::cin, line)) {
        PersonInfo info;
        //std::istringstream record(line);
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        record.clear();
    }
    return 0;
}
