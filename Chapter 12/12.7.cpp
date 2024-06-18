//Exercise 12.7: Redo the previous exercise, this time using shared_ptr.

#include <vector>
#include <iostream>
#include <memory>

std::shared_ptr<std::vector<int>> createVec()
{
    return std::make_shared<std::vector<int>>();
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
    auto vec = createVec();
    fillVec(*vec);
    printVec(*vec);
    return 0;
}
