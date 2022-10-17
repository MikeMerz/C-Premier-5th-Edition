#include <vector>

/*Exercise 3.42: Write a program to copy a vector of ints into an array of
ints*/

int main() {
    std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr[11];
    int *beginIter = arr;
    for(int& i : vec)
    {
        *(beginIter) = i;
        ++beginIter;
    }
    return 0;
}