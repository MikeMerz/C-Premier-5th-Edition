/*Exercise 3.36: Write a program to compare two arrays for equality. Write a
similar program to compare two vectors.*/

#include <iostream>
#include <vector>

bool isArraysEqual(const int arr[], const int arrSec[],int sizeFirst, int sizeSec)
{
    auto startFirstArray = arr;
    auto startSecArray = arrSec;
    auto endFirstArray = &arr[sizeFirst];
    auto endSecArray = &arrSec[sizeSec];

    while(startFirstArray != endFirstArray && startSecArray != endSecArray)
    {
        if(*(startSecArray) != *startFirstArray)
            return false;
        ++startFirstArray;
        ++startSecArray;
    }
    return true;
}

template<class T>
bool isVectorsEqual(std::vector<T> firstVec, std::vector<T> secVec)
{
    if(firstVec.size() != secVec.size())
        return false;
    for(decltype(firstVec.size()) i=0;i < firstVec.size();++i)
    {
        if(firstVec[i] != secVec[i])
            return false;
    }
    return true;
}
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arrSec[] = {1, 2, 3, 4, 5, 6, 7, 8, 7, 10};

    isArraysEqual(arr, arrSec, 10, 10);

    std::vector<int> firstVec(10 , 5);
    std::vector<int> secVec(10 , 10);

    isVectorsEqual(firstVec,secVec); // similiar to firstVec == secVec;
    return 0;
}