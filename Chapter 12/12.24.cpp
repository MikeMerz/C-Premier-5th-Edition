//Exercise 12.24: Write a program that reads a string from the standard input
//into a dynamically allocated character array. Describe how your program
//handles varying size inputs. Test your program by giving it a string of data
//that is longer than the array size you’ve allocated.

#include <iostream>

int main()
{

    //First version, with no size validation in this version the size is not validated so we read the entire input which
    //could cause number of problems and is a security vulnerability for attacks of buffer overflow etc.
//    int size =0;
//    std::cout << "Enter size of input:";
//    std::cin >> size;
//    char* st = new char[size+1]();
//    std::cout << "Enter input:";
//    std::cin >> st;

    //Second version, with size validation, here size is validated and we only read the amount that was given, could also
    //cause problems if the input size is too big adding a limit of the size itself is most appropiate.
    int size =0;
    std::cout << "Enter size of input:";
    std::cin >> size;
    std::cin.ignore();
    char* st = new char[size+1]();
    std::cout << "Enter input:";
    std::cin.get(st,size+1);
    return 0;
}
