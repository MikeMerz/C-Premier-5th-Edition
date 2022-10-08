/*Exercise 3.22: Revise the loop that printed the first paragraph in text to
instead change the elements in text that correspond to the first paragraph
to all uppercase. After you’ve updated text, print its contents.*/

#include <iostream>
#include <vector>
#include  <algorithm>

using std::vector, std::cin, std::string, std::cout, std::endl;

int main() {
    vector<string> text;
    string line;
    while(getline(cin,line))
    {
        if(line == "end")
            break;
        text.push_back(line);
    }
    for (auto it = text.begin();it != text.cend() && !it->empty(); ++it)
    {
        std::for_each(it->begin(), it->end(), [](char &c){c= toupper(c);});
    }

    for (auto & elem : text)
    {
        cout << elem << endl;
    }
    return 0;
}
