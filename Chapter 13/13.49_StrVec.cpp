
#include <algorithm>
#include "13.49_StrVec.h"

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

StrVec::~StrVec() {
    free();
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
    size > size() ? expandStrVec() : decreaseStrVec();

}

