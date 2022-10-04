/*Exercise 3.2: Write a program to read the standard input a line at a time.
Modify your program to read a word at a time.*/

#include <iostream>

using std::string, std::cin, std::cout, std::endl;

void readWords() {
    string word;
    while(cin >> word)
    {
        cout << word << endl;
    }
}

void readLines() {
    string line;

    while(getline(cin, line))
    {
        cout << line << endl;
    }
}

int main() {
    readLines();
    readWords();
    return 0;
}
