//Exercise 8.4: Write a function to open a file for input and read its contents
//into a vector of strings, storing each line as a separate element in the
//vector.

#include <vector>
#include <string>
#include <fstream>

void func()
{
    std::ofstream out("somefile.txt");
    std::string buffer;
    buffer.append("Life is pretty\n");
    buffer.append("surprising\n");
    buffer.append("Am I right?\n");
    if(out.is_open())
    {
        out << buffer;
    }
    out.close();

    std::vector<std::string> fileVec;
    std::string line;
    std::ifstream in("somefile.txt");
    if(in.is_open())
    {
        std::string temp;
        while(std::getline(in,temp)){
            fileVec.push_back(temp);
        }
    }
}
int main()
{
    func();
}