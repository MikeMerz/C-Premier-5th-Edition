/*xercise 3.35: Using pointers, write a program to set the elements in an
array to zero*/

#include <iostream>

using std::cin;
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(auto iter = arr; iter != &arr[10];iter++)
    {
        *(iter) = 0;
    }
    return 0;
}