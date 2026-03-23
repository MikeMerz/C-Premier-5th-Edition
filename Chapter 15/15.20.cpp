//Exercise 15.18: Given the classes from page 612 and page 613, and
//assuming each object has the type specified in the comments, determine
//which of these assignments are legal. Explain why those that are illegal aren’t allowed:
//
//Base *p = &d1; // d1 has type Pub_Derv ---> Legal. since d1 is derived from base publicly.
//p = &d2; // d2 has type Priv_Derv ---> Illegal, conversion to base only for public inheritance.
//p = &d3; // d3 has type Prot_Derv ---> Illegal, conversion to base only for public inheritance.
//p = &dd1; // dd1 has type Derived_from_Public ---> Legal. since dd1 is derived from base publicly.
//p = &dd2; // dd2 has type Derived_from_Private ---> Illegal, conversion to base only for public inheritance.
//p = &dd3; // dd3 has type Derived_from_Protected ---> Illegal, conversion to base only for public inheritance.
//
//Exercise 15.19: Assume that each of the classes from page 612 and page
//613 has a member function of the form:
//void memfcn(Base &b) { b = *this; }
//For each class, determine whether this function would be legal.
//
//Answer:
//Pub_Derv  ---> Legal. Member functions can use the conversion to base regardless of how it inherited from base.
//Priv_Derv ---> Legal. Member functions can use the conversion to base regardless of how it inherited from base.
//Prot_Derv --->Legal. Member functions can use the conversion to base regardless of how it inherited from base.
//Exercise 15.20: Write code to test your answers to the previous two
//exercises.
class Base
{
    void memfcn(Base &b) { b = *this; }
};
struct Pub_Derv : public Base {
    void memfcn(Base &b) { b = *this; }
};
struct Priv_Derv : private Base {
    void memfcn(Base &b) { b = *this; }
};
struct Prot_Derv : protected Base {
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Public : public Pub_Derv
{
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private : public Priv_Derv
{
    void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Prot : public Prot_Derv
{
    void memfcn(Base &b) { b = *this; }
};
int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Prot dd3;
    Base *p = &d1;
    p = &d2;
    p = &d3;
    p = &dd1;
    p = &dd2;
    p = &dd3;
    return 0;
}