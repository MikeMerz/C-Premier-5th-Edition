
#include <algorithm>
#include <iostream>
#include "16.16.h"
template<typename T>
Vec<T>::Vec(const Vec &vec) {
    auto newData= alloc_n_copy(vec.begin(),vec.end());
    elements = newData.first;
    first_free = last = newData.second;
}
template<typename T>
Vec<T>::Vec(Vec &&vec) noexcept : elements(vec.elements), first_free(vec.first_free), last(vec.last) {
    vec.elements = nullptr;
    vec.first_free = nullptr;
    vec.last = nullptr;
}
template<typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = last = data.second;
    return *this;
}
template<typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept{
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
template<typename T>
Vec<T>::~Vec() {
    free();
}
template<typename T>
void Vec<T>::push_back(const T &str) {
    check_n_alloc();
    alloc.construct(first_free++,str);
}
template<typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *start, const T *end) {
    auto data = alloc.allocate(end - start);
    return {data, std::uninitialized_copy(start, end, data)};
}
template<typename T>
void Vec<T>::free() {
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
template<typename T>
void Vec<T>::reallocate() {
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
template<typename T>
Vec<T>::Vec(std::initializer_list<T> il) {
    auto newData= alloc_n_copy(il.begin(),il.end());
    elements = newData.first;
    first_free = last = newData.second;
}
template<typename T>
void Vec<T>::reserve(size_t cap){
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
template<typename T>
void Vec<T>::resize(size_t size) {
    resize(size,std::string());
}
template<typename T>
void Vec<T>::expandStrVec(size_t curSize, const T &str)
{
    if(curSize > capacity())
        reserve(capacity() *2);
    for(size_t i =size();i != curSize; ++i)
    {
        alloc.construct(first_free++,str);
    }
}
template<typename T>
void Vec<T>::decreaseStrVec()
{
    while(first_free != elements)
        alloc.destroy(--first_free);
}
template<typename T>
void Vec<T>::resize(size_t curSize, const T &str) {
    if(curSize == size())return;
    curSize > size() ? expandStrVec(curSize,str) : decreaseStrVec();

}
template<typename T>
bool operator==(const Vec<T>& lhs, const Vec<T>& rhs)
{
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
template<typename T>
bool operator!=(const Vec<T>& lhs, const Vec<T>& rhs)
{
    return !(lhs == rhs);
}

int main()
{
    Vec<int> v = { 1, 2, 3, 4, 5 };

    Vec<int> v2;

    v2 = v;
    std::cout << v2.capacity() << "\n";
    v2.push_back(99);
    v2.resize(2, 2);

    for (auto t : v2)
        std::cout << t << " ";


    std::cout << v2.capacity() << "\n";

    return 0;
}

