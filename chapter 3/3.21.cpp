/*Exercise 3.21: Redo the first exercise from § 3.3.3 (p. 105) using iterators.*/

#include <iostream>
#include <vector>

using std::vector, std::cin, std::string, std::cout, std::endl;

template <typename T> void printVec(vector<T> curVec, int num)
{
    cout << "Question" << " " << num << " " << "Answer is:" << " ";
    for(auto it = curVec.cbegin(); it != curVec.cend(); ++it)
    {
        cout << (*it) << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};

    printVec(v1, 1);
    printVec(v2, 2);
    printVec(v3, 3);
    printVec(v4, 4);
    printVec(v5, 5);
    printVec(v6, 6);
    printVec(v7, 7);
    return 0;
}