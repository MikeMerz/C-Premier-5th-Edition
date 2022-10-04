/*Exercise 3.8: Rewrite the program in the first exercise, first using a while
and again using a traditional for loop. Which of the three approaches do
you prefer and why?*/

#include <iostream>

using std::string, std::cin, std::cout;

int main() {
    string toChange;
    if(cin >> toChange)
    {
        for(char &c : toChange)
        {
            c = 'X';
        }
    }
    cout<<toChange;

    //While
    string::size_type i = 0;
    while(i != toChange.size())
    {
        toChange[i++] = 'X';
    }

    //for
    for(string::size_type j = 0; j != toChange.size(); ++j)
    {
        toChange[j] = 'X';
    }
    return 0;
}
// When possible I prefer the range based approach since in my opinion it's much more readable.