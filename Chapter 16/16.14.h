//Exercise 16.14: Write a Screen class template that uses nontype
//parameters to define the height and width of the Screen.
//Exercise 16.15: Implement input and output operators for your Screen
//template. Which, if any, friends are necessary in class Screen to make the
//input and output operators work? Explain why each friend declaration, if any,
//was needed.

#include <ostream>
template<unsigned Width, unsigned Height> class Screen;
template<unsigned Width, unsigned Height>
std::ostream& operator<<(std::ostream& stream, const Screen<Width, Height> screen)
{
    stream << "Width=" << screen.w << "Height=" << screen.h;
}
template<unsigned Width, unsigned Height>
std::istream& operator>>(std::istream& stream, const Screen<Width, Height> screen)
{
    stream >> screen.w >> screen.h;
    return stream;
}
template<unsigned Width, unsigned Height>
class Screen
{
    friend std::ostream& operator<<(std::ostream& stream, const Screen<Width, Height> screen);
    friend std::istream& operator>>(std::istream& stream, const Screen<Width, Height> screen);
public:

private:
    unsigned w = Width;
    unsigned h = Height;


};