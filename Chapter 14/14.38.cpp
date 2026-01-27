//Exercise 14.38: Write a class that tests whether the length of a given
//string matches a given bound. Use that object to write a program to report
//how many words in an input file are of sizes 1 through 10 inclusive.
//Exercise 14.39: Revise the previous program to report the count of words
//that are sizes 1 through 9 and 10 or more.

#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Range
{
public:
    Range():lowerBound(0), upperBound(0){};
    Range(int lower, int upper):lowerBound(lower), upperBound(upper){};
    bool operator()(std::string& other){return (lowerBound <= other.length() && other.length()<upperBound-1) || upperBound >= other.length();}
private:
    int lowerBound;
    int upperBound;
};

int main()
{
    Range Test(1,10);
    std::ifstream in("data.txt");
    int amountOfWords = 0;
    for(std::string word; in >> word;)
    {
        if(Test(word))
        {
            ++amountOfWords;
        }
    }
    std::cout << amountOfWords;
}