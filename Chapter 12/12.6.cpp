//Exercise 12.6: Write a function that returns a dynamically allocated vector
//of ints. Pass that vector to another function that reads the standard input
//to give values to the elements. Pass the vector to another function to print
//the values that were read. Remember to delete the vector at the
//appropriate time.

#include <vector>
#include <iostream>

std::vector<int>* createVec()
{
    return new std::vector<int>;
}
void fillVec(std::vector<int>& vec)
{
    int num;
    while(std::cin >> num)
    {
        if(num == -1)
            break;
        vec.push_back(num);
    }
}

void printVec(const std::vector<int>& vec)
{
    for(auto& iter : vec)
    {
        std::cout << iter << std::endl;
    }
}

int main()
{
    auto vec = *createVec();
    fillVec(vec);
    printVec(vec);
    return 0;
}

