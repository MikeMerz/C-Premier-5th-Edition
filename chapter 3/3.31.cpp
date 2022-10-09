/*Exercise 3.31: Write a program to define an array of ten ints. Give each
element the same value as its position in the array.*/

int main() {
    int arr[10];
    int i=0;
    for(auto &curNum : arr)
    {
        curNum = i;
        ++i;
    }
    return 0;
}