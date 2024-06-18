#include "12.27.h"
#include <fstream>
#include <sstream>


TextQuery::TextQuery(std::ifstream& fil):file(new std::vector<std::string>)
{
    std::string line;
    int i=0;
    while(std::getline(fil,line))
    {
        file->push_back(line);
        std::istringstream st(line);
        for(std::string text; st >> text;)
        {
            auto &iter = data[text];
            if(!iter)
            {
                iter.reset(new std::set<std::vector<std::string>::size_type>);
            }
            iter->insert(std::vector<std::string>::size_type(i));
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
        os << "\t(line " << (num + 1) << ") "<< *(qr.file->begin() + num) << std::endl;
    return os;
}