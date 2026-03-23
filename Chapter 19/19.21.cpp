//Exercise 19.21: Write your own version of the Token class.
//Exercise 19.22: Add a member of type Sales_data to your Token class.
//Exercise 19.23: Add a move constructor and move assignment to Token.
//Exercise 19.24: Explain what happens if we assign a Token object to itself.
//Exercise 19.25: Write assignment operators that take values of each type in
//the union.

#include <string>
class Sales_data{
public:
    Sales_data() = default;
    ~Sales_data() = default;
    Sales_data(int i):a(i){}
    Sales_data(const Sales_data &rhs):a(rhs.a){}
    Sales_data& operator=(const Sales_data&rhs){
        a = rhs.a;
        return *this;
    }
private:
    int a = 0;
};
class Token {
public:
    Token(): tok(INT), ival{0} { }
    Token(const Token &t): tok(t.tok) { copyUnion(t); }
    Token(Token &&t)
    {
        copyUnion(t);
        tok = std::move(t.tok);
    }
    Token& operator=(Token &&t)
    {
        if(this != &t)
        {
            this->~Token();
            copyUnion(t);
            tok =std::move(t.tok);
        }
        return *this;
    }
    Token &operator=(const Token&);
    ~Token() { if (tok == STR) sval.~basic_string(); }
    Token &operator=(const std::string& st)
    {
        if(tok == SALES) t.~Sales_data();
        if(tok == STR) sval=st;
        else
            new(&sval)std::string(st);
        tok=STR;
        return *this;
    }
    Token &operator=(char c)
    {
        if(tok == STR) sval.~basic_string();
        if(tok == SALES) t.~Sales_data();
        cval = c;
        tok  = CHAR;
        return *this;
    }
    Token &operator=(int& i)
    {
        if(tok == STR) sval.~basic_string();
        if(tok == SALES) t.~Sales_data();
        ival = i;
        tok = INT;
        return *this;
    }
    Token &operator=(double& db)
    {
        if(tok == STR) sval.~basic_string();
        if(tok == SALES) t.~Sales_data();
        dval = db;
        tok=DBL;
        return *this;
    }
    Token &operator=(Sales_data& tem)
    {
        if(tok == STR) sval.~basic_string();
        if(tok == SALES) t= tem;
        else
            new(&t)Sales_data(tem);
        tok=SALES;
        return *this;
    }
private:
    enum {INT, CHAR, DBL, STR, SALES} tok; // discriminant
    union { // anonymous union
        char cval;
        int ival;
        double dval;
        std::string sval;
        Sales_data t;
    };
    void copyUnion(const Token&);
};