//Exercise 8.10: Write a program to store each line from a file in a
//vector<string>. Now use an istringstream to read each element from
//the vector a word at a time.

#include <istream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int main()
{
    std::vector<std::string> fileVec;
    std::string line;
    std::ifstream in("somefile.txt");
    if(in)
    {
        std::string temp;
        while(std::getline(in,temp)){
            fileVec.push_back(temp);
        }
        for(const auto &singleLine : fileVec)
        {
            std::istringstream j(singleLine);
            std::string word;
            j >> word;
            std::cout << word <<std::endl;
        }
    }
}
