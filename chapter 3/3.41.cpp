#include <vector>

/*Exercise 3.41: Write a program to initialize a vector from an array of
ints.*/

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vecFromArr(std::begin(arr),std::end(arr));
    return 0;
}