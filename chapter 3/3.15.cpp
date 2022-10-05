/*Exercise 3.14: Write a program to read a sequence of ints from cin and
store those values in a vector.

 Exercise 3.15: Repeat the previous program but read strings this time*/

#include <iostream>
#include <vector>

using std::vector, std::cin, std::string;

int main() {
    vector<string> seqStr;
    string temp;
    while(cin >> temp)
    {
        seqStr.push_back(temp);
    }
    return 0;
}
