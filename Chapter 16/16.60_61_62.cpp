//Exercise 16.60: Explain how make_shared (§ 12.1.1, p. 451) works.
//Exercise 16.61: Define your own version of make_shared.
#include <memory>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
#include <sstream>
#include "../7.26.h"
//template<typename T, typename ...Args>
//std::shared_ptr<T> make_shared(Args&&... args)
//{
//    std::shared_ptr<T> ret(new T(std::forward<Args>(args)...));
//    return ret;
//}

//Exercise 16.62: Define your own version of hash<Sales_data> and
//define an unordered_multiset of Sales_data objects. Put several
//transactions into the container and print its contents.

//namespace std{
//template<>
//struct hash<Sales_data> {
//    typedef std::size_t result_type;
//    typedef Sales_data argument_type;
//
//    std::size_t operator()(const Sales_data &s) const {
//        return hash<std::string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^ hash<double>()(s.revenue);
//    }
//};
//}

//Exercise 16.63: Define a function template to count the number of
//occurrences of a given value in a vector. Test your program by passing it a
//vector of doubles, a vector of ints, and a vector of strings.
//Exercise 16.64: Write a specialized version of the template from the
//previous exercise to handle vector<const char*> and a program that
//uses this specialization.
//Exercise 16.65: In § 16.3 (p. 698) we defined overloaded two versions of
//debug_rep one had a const char* and the other a char* parameter.
//Rewrite these functions as specializations.
//Exercise 16.66: What are the advantages and disadvantages of overloading
//these debug_rep functions as compared to defining specializations?

//Answer:
//Advantages:
//1)It is possible to overload a templated function with a non-templated one, useful for char*/const char *.
//2)It is possible to overload  function templates but not possible to partially specialize them.
//3)Overload has clearer function matching.
//Disadvantages:
//1)Adding new overloads is harder to maintain and has a higher risk for ambiguities.
//2)A different overload function may be chosen due to implicit conversion while specializations need to excatly match.

//Exercise 16.67: Would defining these specializations affect function
//matching for debug_rep? If so, how? If not, why not?

//Answer:
//It won't affect the function matching itself since function-template specializations are not candidates in overload resolution
//however, it will affect the on which implementation will be used after a template has been selected.

template<typename U>
int count(std::vector<U> vec, U value)
{
    int count =0;
    std::for_each(vec.begin(),vec.end(),[&](U elem){
        if(elem == value)
            ++count;
    });
    return count;
}
template<>
int count(std::vector<const char*> vec,const char* value)
{
    int count =0;
    std::for_each(vec.begin(),vec.end(),[&](const char* elem){
        if(!strcmp(elem,value))
            ++count;
    });
    return count;
}

template <typename T> std::string debug_rep(T *p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}
template<>
std::string debug_rep(char *p)
{
    return std::string{p};
}
template<>
std::string debug_rep(const char *p)
{
    return std::string{p};
}
int main()
{
    std::vector<int> v1{1,2,3,4};
    std::vector<int> v2{1,2,2,4};
    std::cout << count(v1,2) << std::endl << count(v2,2) << std::endl;

    std::vector<std::string> v3{"a","b","c"};
    std::vector<std::string> v4{"a","a","a"};
    std::cout << count(v3,std::string{"a"}) << std::endl << count(v4,std::string{"a"}) << std::endl;

    std::vector<double> v5{1.2,2.0,3.5,4.6};
    std::vector<double> v6{1.2,2.5,2.5,4.6};
    std::cout << count(v5,3.5) << std::endl << count(v6,2.5) << std::endl;

    std::vector<const char*> v7{"abc","aaa","abab"};
    std::vector<const char*> v8{"a","aa","aaaa","aa","abcabc"};
    std::cout << count(v7,"abb") << std::endl << count(v8,"aa") << std::endl;

    std::unordered_multiset<Sales_data> mset;
    Sales_data temp("Big Burgers", 10, 0.85);

    mset.insert(temp);
    mset.emplace("C++ Book of The Century", 20, 9.99);

    return 0;
}