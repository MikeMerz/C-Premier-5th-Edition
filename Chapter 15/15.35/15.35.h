//Exercise 15.35: Implement the Query and Query_base classes, including
//a definition of rep but omitting the definition of eval.
//Exercise 15.36: Put print statements in the constructors and rep members
//and run your code to check your answers to (a) and (b) from the first
//exercise.
//Exercise 15.37: What changes would your classes need if the derived
//classes had members of type shared_ptr<Query_base> rather than of type Query?
#include <algorithm>
#include "../../Chapter 12/12.32_12.33.h"
#include "../../Chapter 12/12.27.h"

class Query_base {
    friend class Query;
protected:
    using line_no = StrBlob::size_type;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual std::string rep() const = 0;
};
class Query {

    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const std::string&){
        std::cout << "Query::Query(const std::string& s)" <<std::endl;
    };
    std::string rep() const { return q->rep(); }
    QueryResult eval(const TextQuery& text) const
    { return q->eval(text); }
private:
    Query(std::shared_ptr<Query_base> query): q(query) {
        std::cout << "Query::Query(std::shared_ptr<Query_base> query)" <<std::endl;
    }
    std::shared_ptr<Query_base> q;
};
class WordQuery: public Query_base {
    friend class Query;
    WordQuery(const std::string &s): query_word(s) {
        std::cout << "WordQuery::WordQuery()" << std::endl;
    };
    QueryResult eval(const TextQuery &t) const override
    { return t.runQuery(query_word); }
    std::string rep() const {
        std::cout << "WodQuery::rep()" << std::endl;
        return query_word; }
    std::string query_word;
};
class NotQuery : public Query_base
{
    friend Query operator~(const Query& operand);
    NotQuery(const Query& q): query(q)
    {
        std::cout << "NotQuery::NotQuery()\n";
    }

    std::string rep() const override
    {
        std::cout << "NotQuery::rep()\n";
        return "~(" + query.rep() + ")";
    }

QueryResult eval(const TextQuery &text) const override
{
    auto result = query.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file().deref().size();
    for (size_t n = 0; n != sz; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
};

    Query query;
};

inline Query operator~(const Query& operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}
class BinaryQuery: public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s): lhs(l), rhs(r), opSym(s) {
        std::cout << "BinaryQuery::BinaryQuery()  where string=" + s << std::endl;
    };
    std::string rep() const {
        std::cout << "BinaryQuery::rep()" << std::endl;
        return "(" + lhs.rep() + " "
               + opSym + " "
               + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};

class AndQuery: public BinaryQuery {
    friend Query operator& (const Query&, const Query&);
    AndQuery(const Query &left, const Query &right):
            BinaryQuery(left, right, "&") {std::cout << "AndQuery::AndQuery()" << std::endl; }
    QueryResult eval(const TextQuery& text) const
    {
        auto left = lhs.eval(text), right = rhs.eval(text);
        auto ret_lines = std::make_shared<std::set<line_no>>();
        std::set_intersection(left.begin(), left.end(),right.begin(), right.end(),
                         inserter(*ret_lines, ret_lines->begin()));
        return QueryResult(rep(), left.get_file(), ret_lines);
    }
};
class OrQuery: public BinaryQuery {
    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &left, const Query &right):
            BinaryQuery(left, right, std::string{"|"}) {
        std::cout << "OrQuery::OrQuery()" << std::endl;
    }
    QueryResult eval(const TextQuery& text) const override{
        auto right = rhs.eval(text), left = lhs.eval(text);
        auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
        ret_lines->insert(right.begin(), right.end());
        return QueryResult(rep(), ret_lines, left.get_file());
    };

};

inline Query operator|(const Query &lhs, const Query& rhs)
{
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
inline Query operator&(const Query &lhs, const Query &rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}


