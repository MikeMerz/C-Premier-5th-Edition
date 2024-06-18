//Exercise 12.27: The TextQuery and QueryResult classes use only
//capabilities that we have already covered. Without looking ahead, write your
//own versions of these classes.

#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <iostream>

class QueryResult;
class TextQuery
{
public:
    explicit TextQuery(std::ifstream&);
    QueryResult runQuery(std::string& s) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string,std::shared_ptr<std::set<std::vector<std::string>::size_type>>> data;
};

class QueryResult
{
    friend std::ostream& print(std::ostream & os, const QueryResult &qr);
public:
    QueryResult(const std::string& qu,std::shared_ptr<std::vector<std::string>> f, std::shared_ptr<std::set<std::vector<std::string>::size_type>> t): query(qu),file(f),pos(t){};


private:
    std::string query;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> pos;

};

