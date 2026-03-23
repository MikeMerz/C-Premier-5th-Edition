//Exercise 17.20: Write your own version of the program to validate phone
//numbers.
//Exercise 17.21: Rewrite your phone number program from § 8.3.2 (p. 323)
//to use the valid function defined in this section.
//Exercise 17.22: Rewrite your phone program so that it allows any number
//of whitespace characters to separate the three parts of a phone number.
//Exercise 17.25: Rewrite your phone program so that it writes only the first
//phone number for each person.
//Exercise 17.26: Rewrite your phone program so that it writes only the
//second and subsequent phone numbers for people with more than one phone
//number.

#include <string>
#include <regex>
#include <iostream>
bool valid(const std::smatch& m)
{
    if(m[1].matched)
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    else
        return !m[3].matched && m[4].str() == m[6].str();
}
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <unordered_map>
using namespace std::regex_constants;
struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main()
{
    std::vector<PersonInfo> people;
    std::string line, word;
    std::ifstream in("somefile.txt");
    std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";
    //17.22
    //std::string phone = "(\()?(\d{3})(\))?([ ])*([-. ])?([ ])*(\d{3})([-. ]?)([ ])*(\d{4})";
    std::regex r(phone);
    std::smatch m;
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
            for (std::sregex_iterator it(++nums.begin(), nums.end(), r), end_it; it != end_it; ++it)
            {
                // for each number
                // check whether the number's formatting is valid
                if (!valid(*it))
                {
                    //17.25
                    std::string fmt = "$2.$5.$7";
                    regex_replace(it->str(), r, fmt, format_first_only);
                    // string in badNums
                    badNums << " " << nums;
                    break;
                }
                else
                    // "writes" to formatted's string
                    formatted << " " << format(nums);
            }
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
//int main()
//{
//    std::string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})";\
//    //17.22
//    //std::string phone = "(\\()?(\\d{3})(\\))?([-.])?([ ])*(\\d{3})([-.]?)([ ]*)(\\d{4})";
//    std::regex r(phone);
//    std::smatch m;
//    std::string s;
//    while (getline(std::cin, s)) {
//        for (std::sregex_iterator it(s.begin(), s.end(), r), end_it;
//             it != end_it; ++it)
//            if (valid(*it))
//                std::cout << "valid: " << it->str() << std::endl;
//            else
//                std::cout << "not valid: " << it->str() << std::endl;
//    }
//    return 0;
//}