#include <algorithm>
#include <iostream>
#include "14.7.h"

CustomString::CustomString(const CustomString &rhs) {
    auto newData= alloc_n_copy(rhs.elements,rhs.endElem);
    elements = newData.first;
    endElem = newData.second;
}

CustomString &CustomString::operator=(const CustomString &rhs) {
    auto newData= alloc_n_copy(rhs.elements,rhs.endElem);
    free();
    elements = newData.first;
    endElem = newData.second;
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
}

std::ostream& operator<<(std::ostream& stream, const CustomString& obj)
{
    stream << obj.elements;
    return stream;
}


