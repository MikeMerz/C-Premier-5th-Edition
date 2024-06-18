//Exercise 11.12: Write a program to read a sequence of strings and ints,
//storing each into a pair. Store the pairs in a vector.

#include <string>
#include <iostream>
#include <vector>

void createWithEmplace()
{
    std::string word;
    std::vector<std::pair<std::string,int>> vec;
    int num;
    while(std::cin >> word >> num)
    {
        vec.emplace_back(word,num);
    }
}

//Exercise 11.13: There are at least three ways to create the pairs in the
//program for the previous exercise. Write three versions of that program,
//creating the pairs in each way. Explain which form you think is easiest to
//write and understand, and why.
void createWithMakePair()
{
    std::string word;
    std::vector<std::pair<std::string,int>> vec;
    int num;
    while(std::cin >> word >> num)
    {
        auto pair = std::make_pair(word,num);
        vec.push_back(pair);
    }
}
void createWithBrackets()
{
    std::string word;
    std::vector<std::pair<std::string,int>> vec;
    int num;
    while(std::cin >> word >> num)
    {
        std::pair<std::string,int> pair{word,num};
        vec.push_back(pair);
    }
}
int main()
{
    //first way is with make pair
    createWithEmplace(); // easiest way,most straight forward way of creating an object.
    createWithMakePair();
    createWithBrackets();
    return 0;
}