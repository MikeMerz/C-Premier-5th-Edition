//Exercise 16.21: Write your own version of DebugDelete.
//Exercise 16.23: Predict when the call operator will be executed in your
//main query program. If your expectations and what happens differ, be sure
//you understand why.
//Exercise 16.24: Add a constructor that takes two iterators to your Blob
//template.
//FINISH ALL OF THEMMMMM
//explicit instantiation A declaration that supplies explicit arguments for all the
//template parameters. Used to guide the instantiation process. If the declaration is
//extern, the template will not be instantiated; otherwise, the template is
//instantiated with the specified arguments. There must be a nonextern explicit
//instantiation somewhere in the program for every extern template declaration.

#include <ostream>
#include <iostream>

class DebugDelete
{
public:
    DebugDelete(std::ostream &s = std::cerr):os(s){}
    template<typename T> void operator()(T *p) const
    {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream& os;
};

//Exercise 16.22: Revise your TextQuery programs from § 12.3 (p. 484) so
//that the shared_ptr members use a DebugDelete as their deleter (§
//12.1.4, p. 468).
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

class QueryResult {
    friend std::ostream &print(std::ostream &os, const QueryResult &qr);

public:
    QueryResult(const std::string &qu, std::shared_ptr<std::vector<std::string>> f,
                std::shared_ptr<std::set<std::vector<std::string>::size_type>> t) : query(qu),
                                                                                    file(f.get(), DebugDelete()),
                                                                                    pos(t.get(), DebugDelete()) {
    };


private:
    std::string query;
    std::shared_ptr<std::vector<std::string>> file;
    std::shared_ptr<std::set<std::vector<std::string>::size_type>> pos;
};