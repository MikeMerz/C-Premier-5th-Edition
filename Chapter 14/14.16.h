//Exercise 14.16: Define equality and inequality operators for your StrBlob
//(§ 12.1.1, p. 456), StrBlobPtr (§ 12.1.6, p. 474), StrVec (§ 13.5, p.
//526), and String (§ 13.5, p. 531) classes.
//Exercise 14.26: Define subscript operators for your StrVec, String,
//StrBlob, and StrBlobPtr classes.
//Exercise 14.27: Add increment and decrement operators to your
//StrBlobPtr class.
//Exercise 14.28: Define addition and subtraction for StrBlobPtr so that
//these operators implement pointer arithmetic (§ 3.5.3, p. 119).

#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <stdexcept>

class StrBlobPtr;
class ConstStrBlobPtr;
class StrBlob
{
    friend bool operator==(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator<(const StrBlob& lhs, const StrBlob &rhs);
    friend bool operator<=(const StrBlob& lhs, const StrBlob &rhs);
    friend bool operator>(const StrBlob& lhs, const StrBlob &rhs);
    friend bool operator>=(const StrBlob& lhs, const StrBlob &rhs);
public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
    StrBlob():data(std::make_shared<std::vector<std::string>>()){}
    StrBlob(std::initializer_list<std::string> li):data(std::make_shared<std::vector<std::string>>(li)){}
    size_type size() const { return data->size();}
    bool empty() const { return data->empty();}
    void push_back(const std::string& str) { return data->push_back(str);}
    void pop_back()
    {
        check(0,"pop_back on empty Blob");
        data->pop_back();
    }
    std::string& front()
    {
        check(0,"front on empty Blob");
        return data->front();
    }
    std::string& back()
    {
        check(0,"back on empty Blob");
        return data->back();
    }
    const std::string& front() const
    {
        check(0,"front on empty Blob");
        return data->front();
    }
    const std::string& back() const
    {
        check(0,"back on empty Blob");
        return data->back();
    }
    StrBlobPtr begin()const;
    StrBlobPtr end()const;
    std::string& operator[](std::size_t n);
    std::string& operator[](std::size_t n)const;

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type index, const std::string& msg) const
    {
        if(index >= data->size())
            throw std::out_of_range(msg);
    }
};
bool operator==(const StrBlob& lhs, const StrBlob& rhs);
bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
bool operator<(const StrBlob& lhs, const StrBlob &rhs);
bool operator<=(const StrBlob& lhs, const StrBlob &rhs);
bool operator>(const StrBlob& lhs, const StrBlob &rhs);
bool operator>=(const StrBlob& lhs, const StrBlob &rhs);
class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
    friend bool operator<(const StrBlobPtr& lhs, const StrBlobPtr &rhs);
    friend bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr &rhs);
    friend bool operator>(const StrBlobPtr& lhs, const StrBlobPtr &rhs);
    friend bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr &rhs);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(const StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz) { }
    StrBlobPtr& incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    std::string& deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    std::string& operator*() const;
    std::string* operator->() const;
    std::size_t getCurr() const{return curr;}
    StrBlobPtr& operator+=(std::size_t);
    StrBlobPtr& operator-=(std::size_t);
    StrBlobPtr operator+(std::size_t);
    StrBlobPtr operator-(std::size_t);
    StrBlobPtr operator+(std::size_t)const;
    StrBlobPtr operator-(std::size_t)const;
    std::string& operator[](std::size_t n);
    std::string& operator[](std::size_t n)const;
    StrBlobPtr& operator++();
    StrBlobPtr& operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
            throw std::out_of_range(msg);
        return ret;
    }

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
bool operator<(const StrBlobPtr& lhs, const StrBlobPtr &rhs);
bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr& lhs, const StrBlobPtr &rhs);
bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr &rhs);
//CONST StrBlobPtr
class ConstStrBlobPtr
{
    friend bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
    friend bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
    friend bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs);
    friend bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs);
    friend bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs);
    friend bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs);
public:
    ConstStrBlobPtr(): curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0):
            wptr(a.data), curr(sz) { }
    ConstStrBlobPtr& incr()
    {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
    std::string& deref() const
    {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    std::string& operator*() const;
    std::string* operator->() const;
    std::size_t getCurr() const{return curr;}
    ConstStrBlobPtr& operator+=(std::size_t);
    ConstStrBlobPtr& operator-=(std::size_t);
    ConstStrBlobPtr operator+(std::size_t)const;
    ConstStrBlobPtr operator-(std::size_t)const;
    const std::string& operator[](std::size_t n)const;
    ConstStrBlobPtr& operator++();
    ConstStrBlobPtr& operator--();
    ConstStrBlobPtr operator++(int);
    ConstStrBlobPtr operator--(int);
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const
    {
        auto ret = wptr.lock();
        if (!ret)
            throw std::runtime_error("unbound StrBlobPtr");
        if (i >= ret->size())
            throw std::out_of_range(msg);
        return ret;
    }

    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};
bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs);
bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs);
bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs);
bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs);
bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs);
//Exercise 14.23: Define an initializer_list assignment operator for
//your version of the StrVec class.
// Str Vec
class StrVec
{
    friend bool operator==(const StrVec& lhs, const StrVec& rhs);
    friend bool operator!=(const StrVec& lhs, const StrVec& rhs);
    friend bool operator<(const StrVec& lhs, const StrVec &rhs);
    friend bool operator<=(const StrVec& lhs, const StrVec &rhs);
    friend bool operator>(const StrVec& lhs, const StrVec &rhs);
    friend bool operator>=(const StrVec& lhs, const StrVec &rhs);
public:
    StrVec():elements(nullptr), first_free(nullptr), last(nullptr){};
    StrVec(std::initializer_list<std::string>);
    StrVec(const StrVec &vec);
    StrVec(StrVec &&vec) noexcept;
    StrVec& operator=(const StrVec& other);
    StrVec& operator=(StrVec&&) noexcept;
    StrVec &operator=(std::initializer_list<std::string> il);
    std::string& operator[](std::size_t n);
    std::string& operator[](std::size_t n) const;
    ~StrVec();
    void push_back(const std::string&);
    void reserve(size_t cap);
    void resize(size_t size);
    void resize(size_t size, const std::string& vec);
    std::string *begin() const {return elements;}
    std::string *end() const {return first_free;};
    size_t size() const{return first_free-elements;};
    size_t capacity() const{return last-elements;};


private:
    std::allocator<std::string> alloc;
    void check_n_alloc()
    {
        if(size() == capacity())
            reallocate();
    }
    std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);
    void free();
    void reallocate();
    void expandStrVec(size_t size, const std::string &str);
    void decreaseStrVec();
    std::string *elements;
    std::string *first_free;
    std::string *last;

};

bool operator==(const StrVec& lhs, const StrVec& rhs);
bool operator!=(const StrVec& lhs, const StrVec& rhs);
bool operator<(const StrVec& lhs, const StrVec &rhs);
bool operator<=(const StrVec& lhs, const StrVec &rhs);
bool operator>(const StrVec& lhs, const StrVec &rhs);
bool operator>=(const StrVec& lhs, const StrVec &rhs);
//Custom String
class CustomString
{
    friend bool operator==(const CustomString& lhs, const CustomString &rhs);
    friend bool operator!=(const CustomString& lhs, const CustomString &rhs);
    friend bool operator<(const CustomString& lhs, const CustomString &rhs);
    friend bool operator<=(const CustomString& lhs, const CustomString &rhs);
    friend bool operator>(const CustomString& lhs, const CustomString &rhs);
    friend bool operator>=(const CustomString& lhs, const CustomString &rhs);
    friend std::ostream& operator<<(std::ostream& stream, const CustomString& obj);
public:
    CustomString():CustomString(" "){};
    CustomString(const char*);
    CustomString(const CustomString&);
    CustomString(CustomString&&) noexcept;

    CustomString& operator=(const CustomString&);
    CustomString& operator=(CustomString&&);
    char& operator[](std::size_t);
    char& operator[](std::size_t) const;
    ~CustomString();

    const char* c_str()const{return elements;};
    std::size_t size(){return endElem - elements;};
    std::size_t length(){return endElem - elements - 1;};

    char* begin(){return elements;};
    char* end(){return endElem;};

private:
    std::allocator<char> alloc;
    std::pair<char*,char*> alloc_n_copy(const char*,const char*);
    void free();
    char* elements;
    char* endElem;

};

bool operator==(const CustomString& lhs, const CustomString &rhs);
bool operator!=(const CustomString& lhs, const CustomString &rhs);
std::ostream& operator<<(std::ostream& stream, const CustomString& obj);
bool operator<(const CustomString& lhs, const CustomString &rhs);
bool operator>(const CustomString& lhs, const CustomString &rhs);
bool operator>=(const CustomString& lhs, const CustomString &rhs);
bool operator<=(const CustomString& lhs, const CustomString &rhs);