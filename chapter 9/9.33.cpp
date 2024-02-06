//Exercise 9.33: In the final example in this section what would happen if we
//did not assign the result of insert to begin? Write a program that omits
//this assignment to see if your expectation was correct.

#include <vector>
#include <iostream>

/*
 * Answer:
 * If we wouldnt modifiy begin then after inserting the reallocation of vector could kick in and the entire
 * vector will be reallocated leaving begin invalidated, it will not point to the element of the vector.
 * In addition, the end iterator will be recalculated for the vector after the reallocation which could make the loop not stop.
 */

int main()
{
    std::vector<int> vi = {1,2,3,4,5,6,7,8,9,10};
    auto begin = vi.begin();
    while (begin != vi.end()) {
        ++begin; // advance begin because we want to insert after this element
        vi.insert(begin, 42); // insert the new value
        ++begin; // advance begin past the element we just added
    }

    for(int i=0; i < vi.size(); ++i)
    {
        std::cout << vi[i] << std::endl;
    }
    return 0;
}
