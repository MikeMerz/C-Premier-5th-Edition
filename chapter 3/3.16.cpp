/*Exercise 3.16: Write a program to print the size and contents of the
vectors from exercise 3.13. Check whether your answers to that exercise
were correct. If not, restudy § 3.3.1 (p. 97) until you understand why you
were wrong.*/

#include <iostream>
#include <vector>

using std::vector, std::cin, std::string, std::cout, std::endl;

template <typename T> void printVec(vector<T> curVec, int num)
{
    cout << "Question" << " " << num << " " << "Answer is:" << " ";
    for(const auto& elem : curVec)
    {
        cout << elem << " ";
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
