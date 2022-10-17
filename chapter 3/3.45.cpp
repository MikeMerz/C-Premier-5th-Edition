#include <iostream>

/*Exercise 3.45: Rewrite the programs again, this time using auto.*/

int main() {
    constexpr int columnSize = 4;
    constexpr int rowSize = 3;
    int ia[rowSize][columnSize] = { // three elements; each element is an array of size 4
            {0, 1, 2, 3}, // initializers for the row indexed by 0
            {4, 5, 6, 7}, // initializers for the row indexed by 1
            {8, 9, 10, 11} // initializers for the row indexed by 2
    };

    // print using range for
    for(auto &row : ia)
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
    for(auto i= ia; i != ia + rowSize; ++i)
    {
        for(int *j = *i ; j !=  *i + columnSize;++j)
        {
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}