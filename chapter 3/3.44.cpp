#include <iostream>

/*Exercise 3.44: Rewrite the programs from the previous exercises using a
type alias for the type of the loop control variables.*/

int main() {
    constexpr int columnSize = 4;
    constexpr int rowSize = 3;
    typedef const int int_arr[columnSize];
    typedef int (*pointer_array)[columnSize];
    int ia[rowSize][columnSize] = { // three elements; each element is an array of size 4
            {0, 1, 2, 3}, // initializers for the row indexed by 0
            {4, 5, 6, 7}, // initializers for the row indexed by 1
            {8, 9, 10, 11} // initializers for the row indexed by 2
    };

    // print using range for
    for(int_arr &row : ia)
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
    for(pointer_array i= ia; i != ia + rowSize; ++i)
    {
        for(int *j = *i ; j !=  *i + columnSize;++j)
        {
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}