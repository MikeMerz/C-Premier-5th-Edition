/*Exercise 3.14: Write a program to read a sequence of ints from cin and
store those values in a vector.*/

#include <iostream>
#include <vector>

using std::vector, std::cin;

int main() {
    vector<int> seqInt;
    int temp;
    while(cin >> temp)
    {
        seqInt.push_back(temp);
    }
    return 0;
}
