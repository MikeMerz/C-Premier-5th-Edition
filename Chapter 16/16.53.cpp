//Exercise 16.53: Write your own version of the print functions and test
//them by printing one, two, and five arguments, each of which should have
//different types.
//Exercise 16.54: What happens if we call print on a type that doesn’t have
//an << operator?
//Answer:
//Compilation would fail since the call to the << operator won't compile.
//Exercise 16.55: Explain how the variadic version of print would execute if
//we declared the nonvariadic version of print after the definition of the
//variadic version.
//Answer:
//Since name lookup happens where the template is defined, because of that the compiler will not find the nonvariadic template and thus the compiler will fail.
//Exercise 16.56: Write and test a variadic version of errorMsg.
//Exercise 16.57: Compare your variadic version of errorMsg to the
//error_msg function in § 6.2.6 (p. 220). What are the advantages and
//disadvantages of each approach?
//Answer:
//******ANSWER ME*****

#include <ostream>
#include <string>
#include <iostream>
#include <sstream>


template <typename T>
std::string debug_rep(const std::string &s);
std::string debug_rep(const char *p);
template <typename T>
std::string debug_rep(const T& t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}
template<typename T> std::ostream& print(std::ostream &os, const T &t)
{
    return os << t;
}
template<> std::ostream& print(std::ostream &os, const std::string &t)
{
    return os << ('"' + t + '"');
}
template<typename T, typename...args> std::ostream& print(std::ostream &os, const T &t, const args&... rest)
{
    os << t << ", ";
    return print(os, rest...);
}
std::string debug_rep(const std::string &s)
{
    return '"' + s + '"';
}
std::string debug_rep(const char *p) {

    return debug_rep(std::string(p));
}
template<typename ...Args>
std::ostream& errorMsg(std::ostream &os, const Args...rest)
{
    return print(os, debug_rep(rest)...);
}
int main()
{
    int i = 0; double d = 3.14; std::string s = "how now brown cow";
    double e = 8.543;
    double f = 2.2;
    print(std::cout, i);
    print(std::cout, i, d);
    print(std::cout, i, d, s, e, f);

    errorMsg(std::cout, 1, 2, 3, 4, "a", "c", "d", 5.5);
    return 0;
}
