//Exercise 9.49: A letter has an ascender if, as with d or f, part of the letter
//extends above the middle of the line. A letter has a descender if, as with p or
//g, part of the letter extends below the line. Write a program that reads a file
//containing words and reports the longest word that contains neither
//ascenders nor descenders.

#include <string>
#include <fstream>
#include <iostream>

bool isAscenderOrDecender(std::string word)
{
    std::string decenderAcender("gjpqybdtfhkl");
    size_t pos = 0;
    while((pos = word.find_first_of(decenderAcender,pos)) != std::string::npos)
    {
        return true;
    }
    return false;

}

int main()
{
    std::ifstream in("Words.txt");
    std::string word;
    std::string longest;
    if(in)
    {
        while( std::getline(in,word))
        {
            if(!isAscenderOrDecender(word) && longest.size() < word.size())
            {
                longest = word;
            }
        }
    }
    std::cout << longest;
    return 0;
}