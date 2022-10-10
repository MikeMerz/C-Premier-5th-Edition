#include <cstddef>
#include <vector>

/*Exercise 3.32: Copy the array you defined in the previous exercise into
another array. Rewrite your program to use vectors*/

int main() {
    int arr[10];
    int i=0;
    for(auto &curNum : arr)
    {
        curNum = i;
        ++i;
    }

    int secArr[10];
    for(size_t j=0; j < 10; ++j)
    {
        secArr[j] = arr[j];
    }

    //Using vectors
    std::vector<int> arrVec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::vector<int> secVec(arrVec);

    return 0;
}