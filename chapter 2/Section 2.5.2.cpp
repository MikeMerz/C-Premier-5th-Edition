#include <iostream>

int main() {
    int i = 0, &r = i;
    auto a = r;
    const int ci = i, &cr = ci;
    auto b = ci; // b is an int (top-level const in ci is dropped)
    auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
    auto d = &i; // d is an int*(& of an int object is int*)
    auto e = &ci;
    auto &g = ci;

    /*Exercise 2.33: Using the variable definitions from this section, determine
    what happens in each of these assignments:

    a = 42; -> Assignment is OK.
    b = 42; -> Assignment is OK.
    c = 42; -> Assignment is OK.
    d = 42; -> Assignment is illegal, since d is int* and we try to assign int.
    e = 42; -> Assignment is illegal, since e is const int* and we try to assign int.
    g = 42; -> Assignment is illegal, since g is const int& we cannot assign to it.*/

    /*Exercise 2.34: Write a program containing the variables and assignments
    from the previous exercise. Print the variables before and after the
    assignments to check whether your predictions in the previous exercise were
    correct. If not, study the examples until you can convince yourself you knowC++ Primer, Fifth Edition
    what led you to the wrong conclusion.*/

    std::cout<<"a before: "<<a;
    a=42;
    std::cout<<"a after: "<<a;

    std::cout<<"b before: "<<b;
    b=42;
    std::cout<<"b after: "<<b;

    std::cout<<"c before: "<<c;
    c=42;
    std::cout<<"c after: "<<c;

    std::cout<<"d before: "<<d;
    d=42;
    std::cout<<"d after: "<<d;

    std::cout<<"e before: "<<e;
    e=42;
    std::cout<<"e after: "<<e;

    std::cout<<"g before: "<<g;
    g=42;
    std::cout<<"g after: "<<g;

    /*Exercise 2.35: Determine the types deduced in each of the following
    definitions. Once you’ve figured out the types, write a program to see
    whether you were correct.

    const int i = 42;
    auto j = i; const auto &k = i; auto *p = &i;
    const auto j2 = i, &k2 = i;

     i is of type const int.
     j is of type  int.
     k is of type const int &
     p is of type int*
     j2 is of type const int.
     k2 is of type const int&
     */

    return 0;
}
