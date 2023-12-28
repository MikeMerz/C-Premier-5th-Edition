//Exercise 7.58: Which, if any, of the following static data member
//declarations and definitions are errors? Explain why.

//example.h
//class Example {
//public:
//static double rate = 6.5;
//static const int vecSize = 20;
//static vector<double> vec(vecSize);
//};
//example.cpp
//#include "example.h"
//double Example::rate;
//vector<double> Example::vec;

/*
 * Answer:
 * Since rate is static it can not be initialized inside the body so its initialization needs to be moved to example.cpp
 * Vec also cannot be initialized since parentheses cannot be used as in-class initializor inside the body and instead need only to be declared in example.h and initialized in example.cpp
 */