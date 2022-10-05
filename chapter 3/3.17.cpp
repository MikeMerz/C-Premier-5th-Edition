/*Exercise 3.17: Read a sequence of words from cin and store the values a
vector. After you’ve read all the words, process the vector and change
each word to uppercase. Print the transformed elements, eight words to a
line.*/

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector, std::cin, std::string, std::cout, std::endl;

int main() {
    vector<string> seqStr;
    string temp;
    while(cin >> temp)
    {
        if(temp == "end")
            break;
        seqStr.push_back(temp);
    }
    //manual upper case.
    for(auto &elem : seqStr)
    {
        for(auto &letter : elem)
        {
            letter = toupper(letter);
        }
    }
    //built-in upper case
    //std::transform(seqStr.begin(), seqStr.end(), seqStr.begin(),::toupper);
    
    for(decltype(seqStr.size()) i = 0;i < seqStr.size(); ++i)
    {
        if(i % 8 == 0)
        {
            cout << endl;
        }
        cout << seqStr[i] << " ";
    }
    return 0;
}
