//Exercise 9.51: Write a class that has three unsigned members
//representing year, month, and day. Write a constructor that takes a string
//representing a date. Your constructor should handle a variety of date
//formats, such as January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.

#include <string>
#include <vector>
#include <iostream>

static std::vector<std::string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
static std::string letters = {"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"};
static std::string numbers = {"0123456789"};
class Date
{
public:
    Date(const std::string &dateFormat)
    {
        auto startingDayIndex = dateFormat.find_first_of(numbers);
        auto endDayIndex = dateFormat.find_first_not_of(numbers,startingDayIndex);
        day = std::stoi(dateFormat.substr(startingDayIndex,endDayIndex));

        std::string::size_type startingYearIndex;
        std::string::size_type endYearIndex;

        auto monthStartingIndex = dateFormat.find_first_of(letters);
        if(monthStartingIndex != std::string::npos)
        {
            for(int i=0;i < months.size();++i)
            {
                if(dateFormat.substr(monthStartingIndex,3) == months[i])
                {
                    month = i + 1;
                }
            }
            startingYearIndex = dateFormat.find_first_of(numbers,endDayIndex);
            endYearIndex = dateFormat.find_first_not_of(numbers,startingYearIndex);
        }
        else
        {
            auto startingMonthIndex = dateFormat.find_first_of(numbers,endDayIndex);
            auto endMonthIndex = dateFormat.find_first_not_of(numbers,startingMonthIndex);
            month = std::stoi(dateFormat.substr(startingMonthIndex,endMonthIndex));

            startingYearIndex = dateFormat.find_first_of(numbers,endMonthIndex);
            endYearIndex = dateFormat.find_first_not_of(numbers,startingYearIndex);
        }


        year = std::stoi(dateFormat.substr(startingYearIndex,endYearIndex));

    }

    unsigned int day;
    unsigned int month;
    unsigned int year;
};

int main()
{
    Date k("December 10, 1990");
    std::cout << k.day <<" "<<k.month<< " " << k.year<<std::endl;
    Date k1("16/6/1994");
    std::cout << k1.day <<" "<<k1.month<< " " << k1.year<<std::endl;
    Date k2("29 / 12 / 1994");
    std::cout << k2.day <<" "<<k2.month<< " " << k2.year<<std::endl;
    Date k3("15 10 1990");
    std::cout << k3.day <<" "<<k3.month<< " " << k3.year<<std::endl;
    Date k4("10??12++1990");
    std::cout << k4.day <<" "<<k4.month<< " " << k4.year<<std::endl;
    Date k5("Dec 10, 1990");
    std::cout << k5.day <<" "<<k5.month<< " " << k5.year<<std::endl;
    Date k6("  Dec 10 1990 ");
    std::cout << k6.day <<" "<<k6.month<< " " << k6.year<<std::endl;
    return 0;
}

