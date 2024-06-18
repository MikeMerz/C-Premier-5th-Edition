//Exercise 12.32: Rewrite the TextQuery and QueryResult classes to use
//a StrBlob instead of a vector<string> to hold the input file.

//Exercise 12.33: In Chapter 15 we’ll extend our query system and will need
//some additional members in the QueryResult class. Add members named
//begin and end that return iterators into the set of line numbers returned
//by a given query, and a member named get_file that returns a
//shared_ptr to the file in the QueryResult object.

#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <iostream>
#include "12.22.h"

class QueryResult;
class TextQuery
{
public:
    explicit TextQuery(std::ifstream&);
    QueryResult runQuery(std::string& s) const;
private:
    StrBlob file;
    std::map<std::string,std::shared_ptr<std::set<StrBlob::size_type>>> data;
};

class QueryResult
{
    friend std::ostream& print(std::ostream & os, const QueryResult &qr);
public:
    QueryResult(const std::string& qu,StrBlob f, std::shared_ptr<std::set<StrBlob::size_type>> t): query(qu),file(f),pos(t){};

    StrBlobPtr get_file(){return StrBlobPtr{file};}
    std::set<StrBlob::size_type>::iterator begin(){return pos->begin();}
    std::set<StrBlob::size_type>::iterator end(){return pos->end();}


private:
    std::string query;
    StrBlob file;
    std::shared_ptr<std::set<StrBlob::size_type>> pos;

};


