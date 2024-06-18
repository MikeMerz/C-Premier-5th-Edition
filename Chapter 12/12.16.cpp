//Exercise 12.16: Compilers don’t always give easy-to-understand error
//messages if we attempt to copy or assign a unique_ptr. Write a program
//that contains these errors to see how your compiler diagnoses them.

#include <memory>

int main()
{
//    std::unique_ptr<int> p(new int(42));
//    std::unique_ptr<int> q(p.get());
    int ix = 1024, *pi = &ix, *pi2 = new int(2048);
    typedef std::unique_ptr<int> IntP;
    //IntP p0(ix);
    IntP p1(pi);
    IntP p2(pi2);
    IntP p3(&ix);
    IntP p4(new int(2048));
    IntP p5(p2.get());
    return 0;
}
