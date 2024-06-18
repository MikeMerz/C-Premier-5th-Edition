//Exercise 12.30: Define your own versions of the TextQuery and
//QueryResult classes and execute the runQueries function from § 12.3.1
//(p. 486).

#include <fstream>
#include "12.32_12.33.h"

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;

        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.runQuery(s)) << std::endl;
    }
}

int main()
{
    std::ifstream file("rules.txt");
    runQueries(file);
    return 0;
}
