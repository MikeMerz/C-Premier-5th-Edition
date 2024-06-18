//Exercise 12.26: Rewrite the program on page 481 using an allocator.

#include <memory>
#include <string>
#include <iostream>

int main()
{
    std::allocator<std::string> alloc;
    size_t size = 10;
    auto const p = alloc.allocate(10);
    std::string s;
    auto q = p;
    while(std::cin >> s &&  q != p + size)
    {
        alloc.construct(q++,s);
    }

    while(q != p)
    {
        alloc.destroy(q--);
    }
    alloc.deallocate(p, size);
    return 0;
}

