
#include <string>
#include <iostream>
#include "7.6.h"

int main() {
    Sales_data total;
    if (read(std::cin, total)) {
        Sales_data trans;
        while (read(std::cin,trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(std::cout,total);
                total = trans;
            }
        }
        print(std::cout,total);
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }

    return 0;
}