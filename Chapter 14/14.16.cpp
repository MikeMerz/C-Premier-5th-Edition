
#include "14.16.h"
#include <algorithm>
#include <iostream>

StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr{*this};
}

StrBlobPtr StrBlob::end() const
{
    auto ret = StrBlobPtr{*this, data->size()};
    return ret;
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
    return *lhs.data == *rhs.data;
}
bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
    return !(lhs == rhs);
}
bool operator<(const StrBlob& lhs, const StrBlob &rhs)
{
    return *lhs.data < *rhs.data;
}
bool operator<=(const StrBlob& lhs, const StrBlob &rhs)
{
    return !(lhs > rhs);
}
bool operator>(const StrBlob& lhs, const StrBlob &rhs)
{
    return !(lhs <= rhs);
}
bool operator>=(const StrBlob& lhs, const StrBlob &rhs)
{
    return !(lhs < rhs);
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr &rhs)
{
    return lhs.curr < rhs.curr;
}
bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr &rhs)
{
    return !(lhs > rhs);
}
bool operator>(const StrBlobPtr& lhs, const StrBlobPtr &rhs)
{
    return lhs.curr > rhs.curr;
}
bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr &rhs)
{
    return !(lhs < rhs);
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    return lhs.curr == rhs.curr;
}
bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.curr < rhs.curr;
}
bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs > rhs);
}
bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs)
{
    return lhs.curr > rhs.curr;
}
bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs < rhs);
}
std::string& StrBlob::operator[](std::size_t n)
{
    return (*data)[n];
}
std::string& StrBlob::operator[](std::size_t n)const
{
    return (*data)[n];
}
std::string& StrBlobPtr::operator[](std::size_t n)
{
    auto p = check(curr, "index past end");
    return (*p)[n];
}
std::string& StrBlobPtr::operator[](std::size_t n)const
{
    auto p = check(curr, "index past end");
    return (*p)[n];
}

StrBlobPtr& StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;

}
StrBlobPtr& StrBlobPtr::operator--()
{
    --curr;
    check(-1, "increment past end of StrBlobPtr");
    return *this;
}
StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}
StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator+(std::size_t n)
{
    StrBlobPtr ret = *this;
    ret+=n;
    return ret;
}
StrBlobPtr StrBlobPtr::operator-(std::size_t n)
{
    StrBlobPtr ret = *this;
    ret-=n;
    return ret;
}
StrBlobPtr StrBlobPtr::operator+(std::size_t n) const
{
    StrBlobPtr ret = *this;
    ret+=n;
    return ret;
}
StrBlobPtr StrBlobPtr::operator-(std::size_t n) const
{
    StrBlobPtr ret = *this;
    ret-=n;
    return ret;
}
StrBlobPtr& StrBlobPtr::operator+=(std::size_t n)
{
    curr+=n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}
StrBlobPtr& StrBlobPtr::operator-=(std::size_t n)
{
    curr-=n;
    check(-1, "increment past end of StrBlobPtr");
    return *this;
}
std::string& StrBlobPtr::operator*() const
{ auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
std::string* StrBlobPtr::operator->() const {
    return & this->operator*();
}
const std::string& ConstStrBlobPtr::operator[](std::size_t n)const
{
    auto p = check(curr, "index past end");
    return (*p)[n];
}

ConstStrBlobPtr& ConstStrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;

}
ConstStrBlobPtr& ConstStrBlobPtr::operator--()
{
    --curr;
    check(-1, "increment past end of StrBlobPtr");
    return *this;
}
ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
    ConstStrBlobPtr ret = *this;
    ++*this;
    return ret;
}
ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
    ConstStrBlobPtr ret = *this;
    --*this;
    return ret;
}
ConstStrBlobPtr  ConstStrBlobPtr::operator+(std::size_t n) const
{
    ConstStrBlobPtr ret = *this;
    ret+=n;
    return ret;
}
ConstStrBlobPtr ConstStrBlobPtr::operator-(std::size_t n) const
{
    ConstStrBlobPtr ret = *this;
    ret-=n;
    return ret;
}
ConstStrBlobPtr& ConstStrBlobPtr::operator+=(std::size_t n)
{
    curr+=n;
    check(curr, "increment past end of StrBlobPtr");
    return *this;
}
ConstStrBlobPtr& ConstStrBlobPtr::operator-=(std::size_t n)
{
    curr-=n;
    check(-1, "increment past end of StrBlobPtr");
    return *this;
}
std::string& ConstStrBlobPtr::operator*() const
{ auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
std::string* ConstStrBlobPtr::operator->() const {
    return & this->operator*();
}
CustomString::CustomString(const CustomString &rhs) {
    auto newData= alloc_n_copy(rhs.elements,rhs.endElem);
    elements = newData.first;
    endElem = newData.second;
    std::cout << "I'm at copy constructor" << std::endl;
}
CustomString::CustomString(CustomString &&rhs) noexcept :elements(rhs.elements),endElem(rhs.endElem) {
    rhs.elements = nullptr;
    rhs.endElem = nullptr;
    std::cout << "I'm at move constructor" << std::endl;
}

CustomString &CustomString::operator=(const CustomString &rhs) {
    auto newData= alloc_n_copy(rhs.elements,rhs.endElem);
    free();
    elements = newData.first;
    endElem = newData.second;
    std::cout << "I'm at copy operator" << std::endl;
    return *this;
}

CustomString &CustomString::operator=(CustomString &&rhs) {
    if(this != &rhs)
    {
        free();
        elements = rhs.elements;
        endElem = rhs.endElem;
        rhs.elements = nullptr;
        rhs.endElem = nullptr;
    }
    std::cout << "I'm at move operator" << std::endl;
    return *this;
}
CustomString::~CustomString() {
    free();

}

std::pair<char *, char *> CustomString::alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e-b);
    return {data, std::uninitialized_copy(b,e,data)};
}

void CustomString::free() {
    if(elements)
    {
        std::for_each(elements, endElem, [this](auto& c){
            alloc.destroy(&c);
        });
        alloc.deallocate(elements, endElem - elements);
    }
}

CustomString::CustomString(const char *s) {
    if(!s) return;
    char *sl = const_cast<char*>(s);
    while (*sl)
        ++sl;
    auto newData = alloc_n_copy(s, sl);
    elements = newData.first;
    endElem = newData.second;
    std::cout << "I'm at copy constructor" << std::endl;
}

bool operator==(const CustomString& lhs, const CustomString &rhs)
{
    return std::equal(lhs.elements, lhs.endElem, rhs.elements);
}

bool operator!=(const CustomString& lhs, const CustomString &rhs)
{
    return !(lhs == rhs);
}
char& CustomString::operator[](std::size_t n)
{
    return elements[n];
}
char& CustomString::operator[](std::size_t n) const
{
    return elements[n];
}
std::ostream& operator<<(std::ostream& stream, const CustomString& obj)
{
    stream << obj.c_str();
    return stream;
}

bool operator<(const CustomString& lhs, const CustomString &rhs)
{
    return std::lexicographical_compare(lhs.elements, lhs.endElem, rhs.elements, rhs.endElem);
}

bool operator>(const CustomString& lhs, const CustomString &rhs)
{
    return rhs < lhs;
}

bool operator>=(const CustomString& lhs, const CustomString &rhs)
{
    return !(lhs < rhs);
}
bool operator<=(const CustomString& lhs, const CustomString &rhs)
{
    return !(rhs < lhs);
}


StrVec::StrVec(const StrVec &vec) {
    auto newData= alloc_n_copy(vec.begin(),vec.end());
    elements = newData.first;
    first_free = last = newData.second;
}

StrVec::StrVec(StrVec &&vec) noexcept :elements(vec.elements),first_free(vec.first_free),last(vec.last) {
    vec.elements = nullptr;
    vec.first_free = nullptr;
    vec.last = nullptr;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = last = data.second;
    return *this;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept{
    if(this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free =rhs.first_free;
        last = rhs.last;
        rhs.elements = nullptr;
        rhs.first_free = nullptr;
        rhs.last = nullptr;
    }
    return *this;
}

StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = last = data.second;
    return *this;
}

StrVec::~StrVec() {
    free();
}
std::string& StrVec::operator[](std::size_t n)
{
    return elements[n];
}
std::string& StrVec::operator[](std::size_t n) const
{
    return elements[n];
}
void StrVec::push_back(const std::string &str) {
    check_n_alloc();
    alloc.construct(first_free++,str);
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *start, const std::string *end) {
    auto data = alloc.allocate(end - start);
    return {data, std::uninitialized_copy(start, end, data)};
}

void StrVec::free() {
    if(elements)
    {
        for(auto iter=first_free; iter > elements;)
        {
            alloc.destroy(--iter);
        }
        alloc.deallocate(elements,last - elements);
    }
    //13.43
    //std::for_each(elements, first_free,[&](auto& iter){
    //     alloc.destroy(&iter);
    //});
    //I would prefer this version since we are giving more responsibility to the standard library which is less prone to mistakes
}

void StrVec::reallocate() {
    auto newCapacity = size() ? size()*2:1;
    auto newData = alloc.allocate(newCapacity);
    auto dest = newData;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    elements = newData;
    first_free = dest;
    last = elements + newCapacity;
}

StrVec::StrVec(std::initializer_list<std::string> il) {
    auto newData= alloc_n_copy(il.begin(),il.end());
    elements = newData.first;
    first_free = last = newData.second;
}

void StrVec::reserve(size_t cap){
    if(cap < capacity())
        return;
    auto newData = alloc.allocate(cap);
    auto dest = newData;
    auto elem = elements;
    for(size_t i = 0; i != size(); ++i)
    {
        alloc.construct(dest++,std::move(*elem++));
    }
    free();
    elements = newData;
    first_free = dest;
    last = elements + cap;
}

void StrVec::resize(size_t size) {
    resize(size,std::string());
}
void StrVec::expandStrVec(size_t size, const std::string &str)
{
    if(size > capacity())
        reserve(capacity() *2);
    for(size_t i =size();i != size; ++i)
    {
        alloc.construct(first_free++,str);
    }
}
void StrVec::decreaseStrVec()
{
    while(first_free != elements)
        alloc.destroy(--first_free);
}
void StrVec::resize(size_t size, const std::string &str) {
    if(size == size())return;
    size > size() ? expandStrVec(size,str) : decreaseStrVec();

}

bool operator==(const StrVec& lhs, const StrVec& rhs)
{
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec& lhs, const StrVec &rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

bool operator>(const StrVec& lhs, const StrVec &rhs)
{
    return rhs < lhs;
}

bool operator>=(const StrVec& lhs, const StrVec &rhs)
{
    return !(lhs < rhs);
}
bool operator<=(const StrVec& lhs, const StrVec &rhs)
{
    return !(rhs < lhs);
}







