/*Exercise 3.4: Write a program to read two strings and report whether the
strings are equal. If not, report which of the two is larger. Now, change
        the program to report whether the strings have the same length, and if
not, report which is longer.*/

#include <iostream>

using std::string, std::cin, std::cout, std::endl;


void isEqual(const string &firstString, const string &secondString) {
    if(firstString == secondString)
    {
        cout << "Strings are equal" << endl;
    }
    else
    {
        firstString > secondString ? cout << "First string is larger" : cout << "Second string is larger";
    }
}

void isSizeEqual(const string &firstString, const string &secondString) {
    if(firstString.size() == secondString.size())
    {
        cout << "Sizes are equal" << endl;
    }
    else
    {
        firstString.size() > secondString.size() ? cout << "First string is larger" : cout << "Second string is larger";
    }
}

int main() {
    string firstString, secondString;
    if(cin >> firstString >> secondString)
    {
        isEqual(firstString, secondString);
        isSizeEqual(firstString, secondString);
    }


    return 0;
}
