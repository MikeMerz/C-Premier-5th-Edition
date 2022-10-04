/*Exercise 3.5: Write a program to read strings from the standard input,
        concatenating what is read into one large string. Print the concatenated
        string. Next, change the program to separate adjacent input strings by a
space.*/

#include <iostream>

using std::string, std::cin, std::cout, std::endl;

int main() {
    string firstString, secondString;
    if(cin >> firstString >> secondString)
    {
        cout << firstString + secondString << endl;
        cout << firstString + " " + secondString << endl;
    }
    return 0;
}
