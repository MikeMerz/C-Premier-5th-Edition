//Exercise 12.32: Rewrite the TextQuery and QueryResult classes to use
//a StrBlob instead of a vector<string> to hold the input file.

#include "12.32_12.33.h"
#include <fstream>
#include <sstream>


TextQuery::TextQuery(std::ifstream& fil)
{
    std::string line;
    int i=0;
    while(std::getline(fil,line))
    {
        file.push_back(line);
        std::istringstream st(line);
        for(std::string text; st >> text;)
        {
            auto &iter = data[text];
            if(!iter)
            {
                iter.reset(new std::set<StrBlob::size_type>);
            }
            iter->insert(StrBlob::size_type(i));
        }
        ++i;
    }

}
QueryResult TextQuery::runQuery(std::string& s) const
{
    auto iter = data.find(s);
    if(iter != data.end())
    {
        return QueryResult{s,file,iter->second};
    }
    else
    {
        return QueryResult{s, file,nullptr};
    }
}

std::ostream& print(std::ostream & os, const QueryResult &qr)
{
    os << qr.query << " occurs " << qr.pos->size() << " times" << std::endl;
    for (auto num : *qr.pos)
    {
        StrBlobPtr ptr(qr.file,num);
        os << "\t(line " << (num + 1) << ") "<< ptr.deref() << std::endl;
    }

    return os;
}

//TEST
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
