//Exercise 8.6: Rewrite the bookstore program from § 7.1.1 (p. 256) to read
//its transactions from a file. Pass the name of the file as an argument to main
//(§ 6.2.5, p. 218).

#include <iostream>
#include <fstream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main(int argc, char* argv[]) {
    Sales_data total;
    double price;
    if(argc < 0)
        return -1;
    std::ifstream in(argv[1]);
    if (in.is_open()) {
        in >> total.bookNo >> total.units_sold >> price;
        Sales_data trans;
        while (!in.eof()) {
            in >> trans.bookNo >> trans.units_sold >> price;
            trans.revenue = trans.units_sold * price;
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << total.bookNo << " "
                          << total.units_sold << " "
                          << total.revenue << std::endl;
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << std::endl;
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }

    return 0;
}
