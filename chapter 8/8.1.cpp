//Exercise 8.1: Write a function that takes and returns an istream&. The
//function should read the stream until it hits end-of-file. The function should
//print what it reads to the standard output. Reset the stream so that it is valid
//before returning the stream.

#include <istream>
#include <iostream>
//8.3 The while will be terminated if the input doesn't match or can be converted to the type of i
std::istream &func(std::istream &stream)
{
    int i;
    i = stream.get();
    while(!stream.eof()){std::cout << i;(i = stream.get());}
    stream.clear(stream.rdstate() & ~std::istream::eofbit);
    return stream;
}

/*int main()
{
    std::string j;
    while(std::cin >> j){}
    std::cin.putback(24);
    func(std::cin);
}*/
