//Exercise 17.28: Write a function that generates and returns a uniformly
//distributed random unsigned int each time it is called.
//Exercise 17.29: Allow the user to supply a seed as an optional argument to
//the function you wrote in the previous exercise.
//Exercise 17.30: Revise your function again this time to take a minimum and
//maximum value for the numbers that the function should return.

#include <random>
#include <iostream>

unsigned int generateNum()
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> ret;
    return ret(e);
}
unsigned int generateNumWithSeed(unsigned int seed)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ret;
    return ret(e);
}
unsigned int generateNumWithMinMax(unsigned int min,unsigned int max)
{
    static std::default_random_engine e;
    static std::uniform_int_distribution<unsigned> ret(min, max);
    return ret(e);
}
unsigned int generateNumWithSeedMinMax(unsigned int seed, unsigned int min,unsigned int max)
{
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> ret(min, max);
    return ret(e);
}
int main()
{
    return 0;
}