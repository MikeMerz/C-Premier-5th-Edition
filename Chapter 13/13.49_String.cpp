#include <algorithm>
#include <iostream>
#include "13.49_String.h"

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


