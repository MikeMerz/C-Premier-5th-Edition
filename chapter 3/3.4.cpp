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
        firstString > secondString ? cout << "First string is larger" << endl : cout  << "Second string is larger" << endl;
    }
}

void isSizeEqual(const string &firstString, const string &secondString) {
    if(firstString.size() == secondString.size())
    {
        cout << "Sizes are equal" << endl;
    }
    else
    {
        firstString.size() > secondString.size() ? cout << "First string is larger" << endl : cout << "Second string is larger" << endl;
    }
}

int main() {
    string firstString, secondString;
    if(cin >> firstString >> secondString)
    {
        isEqual(firstString, secondString);
        isSizeEqual(firstString, secondString);
    }

    //Test

    isEqual("hi", "bi"); // First string is large
    isSizeEqual("hi", "bi"); //Sizes are equal

    isEqual("hi", "hiya"); // Second string is larger
    isSizeEqual("hi", "hiya"); // Second string is larger

    isEqual("", "hiya"); // Second string is larger
    isSizeEqual("", "hiya"); // Second string is larger
    return 0;
}
