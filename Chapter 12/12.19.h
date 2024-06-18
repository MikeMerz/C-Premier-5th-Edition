//Exercise 12.19: Define your own version of StrBlobPtr and update your
//StrBlob class with the appropriate friend declaration and begin and end
//members.

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
    StrBlobPtr begin();
    StrBlobPtr end();

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
    StrBlobPtr(StrBlob &a, size_t sz = 0):
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
