//Exercise 9.13: How would you initialize a vector<double> from a
//list<int>? From a vector<int>? Write code to check your answers.

#include <list>
#include <vector>

/*
 * Answer:
 * std::vector<int> vecInt = {10};
 * std::list<int> listInt = {5,10};
 * std::vector<double> vecDouble(vecInt.begin(),vecInt.end());
 * std::vector<double> vecFromList();
 */
int main()
{
    std::vector<int> vecInt = {10};
    std::list<int> listInt = {5,10};
    std::vector<double> vecDouble(vecInt.begin(),vecInt.end());
    std::vector<double> vecFromList(listInt.begin(),listInt.end());
}