//Exercise 10.33: Write a program that takes the names of an input file and
//two output files. The input file should hold integers. Using an
//istream_iterator read the input file. Using ostream_iterators, write
//the odd numbers into the first output file. Each value should be followed by a
//space. Write the even numbers into the second file. Each of these values
//should be placed on a separate line.

#include <vector>
#include <iterator>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

int main()
{
    std::ifstream in("10.33Ints");
    std::ofstream out("even");
    std::ofstream outOdd("odd");

    std::istream_iterator<int> inRead(in);
    std::istream_iterator<int> end;

    std::ostream_iterator<int> outIter(out,"\n");
    std::ostream_iterator<int> outIterOdd(outOdd," ");

    std::vector<int> vec(inRead,end);

    std::copy_if(vec.begin(),vec.end(),outIter,[](int num){
        return !(num%2);
    });

    std::copy_if(vec.begin(),vec.end(),outIterOdd,[](int num){
        return num%2;
    });


    return 0;
}
