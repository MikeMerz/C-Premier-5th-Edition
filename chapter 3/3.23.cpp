/*Exercise 3.23: Write a program to create a vector with ten int elements.
Using an iterator, assign each element a value that is twice its current value.
Test your program by printing the vector.*/

#include <iostream>
#include <vector>

using std::vector, std::cin, std::string, std::cout, std::endl;

void MultiplyAllByTwo(vector<int> &temp) {
    cout << "Old values:" << " ";
    for(auto it = temp.begin(); it != temp.end();++it)
    {
        cout << *it << " " ;
        *it *= 2 ;
    }
    cout << endl;
    cout << "New values:" << " " ;

    for(auto it = temp.begin(); it != temp.end();++it)
    {
        cout << *it << " " ;
    }
    cout << endl;
}

int main() {
    vector<int> v1(10,42);
    vector<int> v2{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v3{-1, 0, 3, 5, -5, 6, 7, 8, 9};
    MultiplyAllByTwo(v1);
    MultiplyAllByTwo(v2);
    MultiplyAllByTwo(v3);

    return 0;
}