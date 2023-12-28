//Exercise 7.57: Write your own version of the Account class.

#include <string>

class Account
{
public:
    Account(): Account("",0.0){};
    Account(const std::string &o, double startAmount):owner(o),amount(startAmount){};
    static double rate(){return intrestRate;}
    static void rate(double);
    void calculate(){amount += amount * intrestRate;}
private:
    std::string owner;
    double amount;
    static constexpr int period = 30;
    double daily_tbl[period];
    static double intrestRate;
    static double initRate();

};

double Account::initRate() {
    return 0;
}

void Account::rate(double newRate)
{
    intrestRate = newRate;
}
