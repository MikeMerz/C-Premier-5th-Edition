//Exercise 8.9: Use the function you wrote for the first exercise in § 8.1.2 (p.
//314) to print the contents of an istringstream object.

#include <istream>
#include <iostream>
#include <sstream>

std::istream &func(std::istream &stream)
{
    std::string line;
    while(std::getline(stream,line))
    {
        std::cout << line;
    }
    stream.clear(stream.rdstate() & ~std::istream::eofbit);
    return stream;
}

int main()
{
    std::istringstream j("THIS IS A GOOD DAY\nISNT IT?\n");
    func(j);
}