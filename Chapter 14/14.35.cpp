//Exercise 14.35: Write a class like PrintString that reads a line of input
//from an istream and returns a string representing what was read. If the
//read fails, return the empty string.
//Exercise 14.36: Use the class from the previous exercise to read the
//standard input, storing each line as an element in a vector.
#include <string>
#include <iostream>
#include <vector>

class ReadToString
{
public:
    ReadToString(std::istream& i=std::cin):os(i){}
    std::string operator()()
    {
        std::string str;
        std::getline(os, str);
        return os ? str : std::string{};
    }
private:
    std::istream& os;
};

int main()
{
    ReadToString r;
    std::vector<std::string> vec;
    for(std::string str; !((str=r()).empty());){vec.push_back(str);}
    for(auto iter = vec.begin(); iter != vec.end();++iter){std::cout << *iter<<std::endl;}
}