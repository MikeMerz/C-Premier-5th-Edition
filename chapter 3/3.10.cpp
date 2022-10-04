/*Exercise 3.10: Write a program that reads a string of characters including
punctuation and writes what was read but with the punctuation removed.*/

#include <iostream>

using std::string, std::cin, std::cout, std::endl;

int main() {
    string original;
    cin >> original;
    for(auto c : original)
    {
        if(!ispunct(c))
        {
            cout << c;
        }
    }
    cout << endl;
    return 0;
}
