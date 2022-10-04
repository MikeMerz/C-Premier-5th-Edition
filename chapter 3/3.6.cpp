/*Exercise 3.6: Use a range for to change all the characters in a string to
        X*/

#include <iostream>

using std::string, std::cin, std::cout, std::endl;

int main() {
    string toChange;
    if(cin >> toChange)
    {
        for(auto &c : toChange)
        {
            c = 'X';
        }
    }
    cout<<toChange;
    return 0;
}
