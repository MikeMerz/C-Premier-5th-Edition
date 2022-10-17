#include <cstring>
#include <iostream>

/*Exercise 3.40: Write a program to define two character arrays initialized
from string literals. Now define a third character array to hold the
concatenation of the two arrays. Use strcpy and strcat to copy the two
arrays into the third*/

int main() {
    char firstCharArr[] = "Hello";
    char secCharArr[] = "World!";
    char conCharArr[13];

    strcpy(conCharArr, firstCharArr);
    strcat(conCharArr, " ");
    strcat(conCharArr, secCharArr);
    std::cout << conCharArr;
    return 0;
}