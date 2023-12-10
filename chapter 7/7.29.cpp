//Exercise 7.29: Revise your Screen class so that move, set, and display
//functions return Screen and check your prediction from the previous
//exercise

#include <iostream>
#include "string"
class Screen
{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos high, pos wid, char c):height(high), width(wid), contents(high*wid,c){}
    Screen(pos high, pos wid):height(high), width(wid), contents(high*wid,' '){}
    char get() const { return contents[cursor];}
    inline char get(pos high, pos wid) const;

    inline Screen set(char c) {contents[cursor] = c; return *this;}
    inline Screen set(pos r, pos col, char ch){contents[r*width + col] = ch;return *this;}

    Screen display(std::ostream &os) { do_display(os); return *this; }
    const Screen display(std::ostream &os) const { do_display(os); return *this; }

    Screen move(pos r, pos c);
private:
    void do_display(std::ostream &os) const {os << contents;}
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline
Screen Screen::move(pos r, pos c)
{
    pos row = r * width;
    cursor = row + c ;
    return *this;
}

char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}
/*
int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
}*/
