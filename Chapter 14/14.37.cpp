//Exercise 14.37: Write a class that tests whether two values are equal. Use
//that object and the library algorithms to write a program to replace all
//instances of a given value in a sequence.

#include <algorithm>
#include <vector>

class test
{
public:
    test(int val):value(val){};
    bool operator()(int other){return value == other;}
private:
    int value;
};

int main()
{
    std::vector<int> vec{1,2,2,2,2,3,4,5,6,7,8,9};
    test Test(2);
    std::replace_if(vec.begin(),vec.end(),Test,-1);

}