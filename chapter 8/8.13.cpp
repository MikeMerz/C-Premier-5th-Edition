//Exercise 8.13: Rewrite the phone number program from this section to read
//from a named file rather than from cin.
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::vector<PersonInfo> people;
    std::string line, word;
    std::ifstream in("somefile.txt");
    if(!in)
        std::cerr << "Error opening file" << std::endl;
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
    for (const auto &entry : people) {
        std::ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (!valid(nums)) {
                badNums << " " << nums;
            } else
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())
            std::cout << entry.name << " "
               << formatted.str() << std::endl;
        else
            std::cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() <<
                 std::endl;
    }
    return 0;
}
