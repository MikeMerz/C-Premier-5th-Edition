//Exercise 17.34: Write a program that illustrates the use of each
//manipulator in Tables 17.17 (p. 757) and 17.18.
//Exercise 17.35: Write a version of the program from page 758, that printed
//the square root of 2 but this time print hexadecimal digits in uppercase.
//Exercise 17.36: Modify the program from the previous exercise to print the
//various floating-point values so that they line up in a column.
//Exercise 17.37: Use the unformatted version of getline to read a file a
//line at a time. Test your program by giving it a file that contains empty lines
//as well as lines that are longer than the character array that you pass to
//getline.
//Exercise 17.38: Extend your program from the previous exercise to print
//each word you read onto its own line.
//Exercise 17.39: Write your own version of the seek program presented in
//this section.

using namespace std;
int main()
{
    cout <<"default format: " << 100 * sqrt(2.0) << '\n'
         << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
         << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << "hexidecimal: " << uppercase << hexfloat << 100 * sqrt(2.0) << '\n'
         << "use defaults: " << defaultfloat << 100 * sqrt(2.0)
         << "\n\n";
}