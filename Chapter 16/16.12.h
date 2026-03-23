//Exercise 16.12: Write your own version of the Blob and BlobPtr
//templates. including the various const members that were not shown in the
//text.
//Exercise 16.13: Explain which kind of friendship you chose for the equality
//and relational operators for BlobPtr.
//Answer:
//I have decided One-To-One friendship since BlobPtr, Blob and operator== should all use the same type.
#include <vector>
template <typename> class BlobPtr;
template <typename> class Blob;
template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);
template<typename T>
class Blob
{
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T> li);
    size_type size()const {return data->size();};
    bool empty() const {return data->empty();}
    void push_back(const T &t){data->push_back(t);}
    void push_back(T &&t){data->push_back(std::move(t));}
    void pop_back();
    T& back();
    T& operator[](size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i, const std::string &msg) const
    {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }

};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) { }
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):
        data(std::make_shared<std::vector<T>>(il)) { }
template <typename T>
T& Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}
template <typename T>
T& Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}
template <typename T>
T& Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
class BlobPtr
{
    friend bool operator ==<T>(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs);
public:
    BlobPtr(): curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0):
            wptr(a.data), curr(sz) { }
    T& operator*() const
    { auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr operator ++(int);
    BlobPtr operator --(int);
private:
    std::shared_ptr<std::vector<T>>check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr ret = *this;
    ++*this;
    return ret;
}
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator ++()
{
    check(curr,"increment past end of StrBlob");
    ++curr;
    return *this;
}
template<typename T>
BlobPtr<T>& BlobPtr<T>::operator --()
{
    -- curr;
    check(curr,"decrement past begin of BlobPtr");

    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    -- curr;
    check(curr,"decrement past begin of BlobPtr");
    return *this;
}