//Exercise 9.50: Write a program to process a vector<string>s whose
//elements represent integral values. Produce the sum of all the elements in
//that vector. Change the program so that it sums of strings that represent
//floating-point values.

#include <vector>
#include <string>
int sumIntFromVec(std::vector<std::string> &vec)
{
    int sum = 0;
    for(auto single : vec)
    {
        sum += stoi(single);
    }
    return sum;
}
double sumDoubleFromVec(std::vector<std::string> &vec)
{
    double sum = 0.0;
    for(auto single : vec)
    {
        try
        {
            double cur = stod(single);
            sum += cur;
        }
        catch(...) {
            continue;
        }
    }
    return sum;
}
