//Exercise 12.22: What changes would need to be made to StrBlobPtr to
//create a class that can be used with a const StrBlob? Define a class
//named ConstStrBlobPtr that can point to a const StrBlob.


#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <stdexcept>

class StrBlobPtr;
class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;
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

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type index, const std::string& msg) const
    {
        if(index >= data->size())
            throw std::out_of_range(msg);
    }
};

class StrBlobPtr
{
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
    std::size_t getCurr() const{return curr;}
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
