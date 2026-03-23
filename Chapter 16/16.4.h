//Exercise 16.4: Write a template that acts like the library find algorithm.
//The function will need two template type parameters, one to represent the
//function’s iterator parameters and the other for the type of the value. Use
//your function to find a given value in a vector<int> and in a
//list<string>.

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
