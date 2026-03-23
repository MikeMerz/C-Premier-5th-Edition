//Exercise 16.4: Write a template that acts like the library find algorithm.
//The function will need two template type parameters, one to represent the
//function’s iterator parameters and the other for the type of the value. Use
//your function to find a given value in a vector<int> and in a
//list<string>.
//Exercise 16.5: Write a template version of the print function from § 6.2.4
//(p. 217) that takes a reference to an array and can handle arrays of any size
//and any element type.
//Exercise 16.6: How do you think the library begin and end functions that
//take an array argument work? Define your own versions of these functions.
//Answer:
//Both are templated functions with one parameter type as the iterator and second as an unsigned size of the obj.
//Exercise 16.7: Write a constexpr template that returns the size of a given
//array.
//Exercise 16.8: In the “Key Concept” box on page 108, we noted that as a
//matter of habit C++ programmers prefer using != to using <. Explain the
//rationale for this habit.
//Answer:
//The rationale behind this habit is that using '!=' lowers the requirements for a templated class and
//more containers define '!=' but do not define relational operators.


#include <vector>
#include <list>
#include <string>
#include <iostream>

//16.4
template<typename Iterator, typename Value>
Iterator find(Iterator first, Iterator last, const Value& val)
{
    while(first != last)
    {
        if(*first == val)
            return first;
    }
    return last;
}

//16.5
template<typename ArrayType>
void print(ArrayType const& arr)
{
    for(const auto& item : arr)
    {
        std::cout << item <<std::endl;
    }
}

//16.6
template<typename Type, unsigned objSize>
Type* begin(const Type (&item)[objSize])
{
    return item[0];
}

template<typename Type, unsigned objSize>
Type* end(const Type (&item)[objSize])
{
    return item[objSize];
}

//16.7
template<typename Type, unsigned objSize>
constexpr std::size_t size(const Type (&item)[objSize])
{
    return objSize;
}

int main()
{
    std::vector<int> vec{1,2,3};
    if(find(vec.begin(), vec.end(), 2) != vec.end())
        std::cout << "Found 2 in Vec" << std::endl;
    if(find(vec.begin(), vec.end(), 5) == vec.end())
        std::cout << "Did not found 5 in vec" << std::endl;
    std::list<std::string> li{"a","bc","abc"};
    if(find(li.begin(), li.end(),"bc") != li.end())
        std::cout << "Found bc in list, good job!" << std::endl;
    if(find(li.begin(), li.end(),"k") == li.end())
        std::cout << "Did not found K in list, good job!" << std::endl;

    //16.5
    std::string st[] = {"a", "b", "c", "aa"};
    std::string st2("WHATTT");
    char chars[3] = {'a', 'b', 'c'};
    int ints[2] = {5, 10};
    print(st);
    print(st2);
    print(chars);
    print(ints);

    //16.6
    if(find(begin(vec), end(vec), 2) != end(vec))
        std::cout << "Found 2 in Vec" << std::endl;
    if(find(begin(vec), end(vec), 5) == end(vec))
        std::cout << "Did not found 5 in vec" << std::endl;
    if(find(begin(li), end(li),"bc") != end(li))
        std::cout << "Found bc in list, good job!" << std::endl;
    if(find(begin(li), end(li),"k") == end(li))
        std::cout << "Did not found K in list, good job!" << std::endl;
    return 0;
}