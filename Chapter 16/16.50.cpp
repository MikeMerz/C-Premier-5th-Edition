//Exercise 16.50: Define the functions from the previous exercise so that they
//print an identifying message. Run the code from that exercise. If the calls
//behave differently from what you expected, make sure you understand why.

#include <iostream>

template <typename T> void f(T x){std::cout << "f(T x) called with= " << x << " f(int) will be instantiated." << std::endl;};
template <typename T> void f(const T* x){std::cout << "f(const T* x) called with= " << x << " f(const int) will be instantiated." << std::endl;};
template <typename T> void g(T x){std::cout << "g(T x) called with= " << x << " g(int) will be instantiated." << std::endl;};
template <typename T> void g(T* x){std::cout << "g(T* x) called with= " << x << " g(int*)/g(const int *) will be instantiated." << std::endl;};

int main()
{
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42); g(p); g(ci); g(p2);
    f(42); f(p); f(ci); f(p2);
    return 0;
}
