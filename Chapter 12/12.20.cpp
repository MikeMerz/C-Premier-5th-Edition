//Exercise 12.20: Write a program that reads an input file a line at a time
//into a StrBlob and uses a StrBlobPtr to print each element in that
//StrBlob.

#include "12.19.h"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream s("rules.txt");
    StrBlob blob;
    std::string line;
    while(std::getline(s,line))
    {
        blob.push_back(line);
    }
    StrBlobPtr start = blob.begin();
    try
    {
        while(true)
        {
            std::cout  << start.deref() <<std::endl;
            start = start.incr();
        }
    }
    catch(...) {
        std::cout << "We have reached EOF"<<std::endl;
    }
    return 0;
}
