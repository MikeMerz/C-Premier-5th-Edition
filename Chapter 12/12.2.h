//Exercise 12.2: Write your own version of the StrBlob class including the
//const versions of front and back.

#include <vector>
#include <string>
#include <memory>
#include <exception>
#include <stdexcept>

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

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type index, const std::string& msg) const
    {
        if(index >= data->size())
            throw std::out_of_range(msg);
    }
};