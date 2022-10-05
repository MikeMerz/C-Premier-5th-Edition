/*Exercise 3.20: Read a set of integers into a vector. Print the sum of each
pair of adjacent elements. Change your program so that it prints the sum of
the first and last elements, followed by the sum of the second and second-tolast, and so on.*/

#include <iostream>
#include <vector>

using std::vector, std::cin, std::cout, std::endl;

void printSumAdj(const vector<int> &nums) {
    //For every two unique elements use i+=2 and add condition for odd size vecs
    /*if(nums.size() % 2 == 1)
        cout << nums[nums.size()-1] << endl;*/
    for(decltype(nums.size()) i = 0; i < nums.size() - 1; ++i)
    {
        cout << nums[i] + nums[i+1] << endl;
    }
}

void printSumSym(const vector<int> &nums) {
    for(decltype(nums.size()) i = 0; i <= nums.size() / 2; ++i)
    {
        cout << nums[i] + nums[nums.size() - i - 1] << endl;
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
