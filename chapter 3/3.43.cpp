#include <vector>
#include <iostream>

/*Exercise 3.43: Write three different versions of a program to print the
elements of ia. One version should use a range for to manage the
iteration, the other two should use an ordinary for loop in one case using
subscripts and in the other using pointers. In all three programs write all the
types directly. That is, do not use a type alias, auto, or decltype to
simplify the code.*/

int main() {
    constexpr int columnSize = 4;
    constexpr int rowSize = 3;
    int ia[rowSize][columnSize] = { // three elements; each element is an array of size 4
            {0, 1, 2, 3}, // initializers for the row indexed by 0
            {4, 5, 6, 7}, // initializers for the row indexed by 1
            {8, 9, 10, 11} // initializers for the row indexed by 2
    };

    // print using range for
    for(const int (&row)[columnSize] : ia)
    {
        for(int col : row)
        {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }

    //print regular using subscripts
    for(int i=0; i < rowSize;++i)
    {
        for(int j=0; j < columnSize;++j)
        {
            std::cout << ia[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //print regular using pointers
    for(int (*i)[columnSize] = ia; i != ia + rowSize;++i)
    {
        for(int *j = *i ; j !=  *i + columnSize;++j)
        {
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}