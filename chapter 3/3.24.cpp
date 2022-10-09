/*Exercise 3.24: Redo the last exercise from § 3.3.3 (p. 105) using iterators..*/

#include <iostream>
#include <vector>

using std::vector, std::cin, std::cout, std::endl;

void printSumAdj(const vector<int> &nums) {
    for(auto it = nums.cbegin(); it != nums.cend() - 1; ++it)
    {
        cout << *it + *(it+1) << endl;
    }
}

void printSumSym(const vector<int> &nums) {
    auto mid = nums.begin() + (nums.end() - nums.begin()) /2;
    for(auto it = nums.cbegin(); it != mid; ++it)
    {
        cout << *it + *(nums.cend() -1  - (it - nums.cbegin())) << endl;
    }
}

int main() {
    vector<int> nums;
    int temp;
    while(cin >> temp)
    {
        if(temp == -1)
            break;
        nums.push_back(temp);
    }

    printSumAdj(nums);
    printSumSym(nums);
    return 0;
}