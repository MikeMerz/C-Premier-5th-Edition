//Exercise 7.32: Define your own versions of Screen and Window_mgr in
//which clear is a member of Window_mgr and a friend of Screen.

#include <iostream>
#include "string"
#include <vector>
class Screen;
class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    Window_mgr();
private:
    std::vector<Screen> screens;
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex i);
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos high, pos wid, char c):height(high), width(wid), contents(high*wid,c){}
    Screen(pos high, pos wid):height(high), width(wid), contents(high*wid,' '){}
    char get() const { return contents[cursor];}
    inline char get(pos high, pos wid) const;

    inline Screen &set(char c) {contents[cursor] = c; return *this;}
    inline Screen &set(pos r, pos col, char ch){contents[r*width + col] = ch;return *this;}

    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }

    Screen &move(pos r, pos c);
private:
    void do_display(std::ostream &os) const {os << contents;}
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline
Screen &Screen::move(pos r, pos c)
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

Window_mgr::Window_mgr():screens({Screen(24, 80, ' ')}){}
void Window_mgr::clear(ScreenIndex i)
{
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
}