//Exercise 7.53: Define your own version of Debug

class Debug{
public:
    constexpr Debug(bool h, bool i, bool oth):hw(h),io(i),other(oth){};
    constexpr Debug(bool b = true):hw(b), io(b), other(b){};

    constexpr bool any(){return hw || io || other;}
    void set_io(bool b){io = b;}
    void set_hw(bool b){hw = b;}
    void set_other(bool b){other = b;}
private:
    bool hw;
    bool io;
    bool other;
};
