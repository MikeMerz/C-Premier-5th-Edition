//Exercise 8.8: Revise the program from the previous exercise to append its
//output to its given file. Run the program on the same output file at least
//twice to ensure that the data are preserved.


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
    std::ofstream out(argv[2], std::ofstream::app);
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
                if(out.is_open())
                {
                    out <<  total.bookNo << " "
                        << total.units_sold << " "
                        << total.revenue << std::endl;
                }
                total.bookNo = trans.bookNo;
                total.units_sold = trans.units_sold;
                total.revenue = trans.revenue;
            }
        }
        if(out.is_open())
        {
            out <<  total.bookNo << " "
                << total.units_sold << " "
                << total.revenue << std::endl;
        }
    } else {
        std::cerr << "No data!" << std::endl;
        return -1;
    }

    return 0;
}

