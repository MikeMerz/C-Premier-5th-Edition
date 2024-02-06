//Exercise 9.15: Write a program to determine whether two vector<int>s
//are equal

#include <vector>

bool compareVecOfInts(std::vector<int> &first, std::vector<int> &second)
{
    if(first.size() != second.size()){return false;}

    for(int i=0; i < first.size(); ++i)
    {
        if(first[i] != second[i])
            return false;
    }
    return true;
}
