//Exercise 15.39: Implement the Query and Query_base classes. Test your
//application by evaluating and printing a query such as the one in Figure 15.3
//(p. 638).
//TODO:
//Exercise 15.40: In the OrQuery eval function what would happen if its
//rhs member returned an empty set? What if its lhs member did so? What if
//both rhs and lhs returned empty sets?
//Exercise 15.41: Reimplement your classes to use built-in pointers to
//Query_base rather than shared_ptrs. Remember that your classes will no
//longer be able to use the synthesized copy-control members.
//Exercise 15.42: Design and implement one of the following enhancements:
//(a) Print words only once per sentence rather than once per line.
//(b) Introduce a history system in which the user can refer to a previous
//query by number, possibly adding to it or combining it with another.
//(c) Allow the user to limit the results so that only matches in a given range
//of lines are displayed.

#include <iosfwd>
#include <iostream>
#include <fstream>
#include "../../Chapter 12/12.32_12.33.h"
#include "../15.35/15.35.h"

int main(int argc, char *argv[])
{
    std::ifstream ifs(argv[1]);
    TextQuery tq(ifs);
    Query q = Query("fiery") & Query("bird") | Query("wind");
    auto result = q.eval(tq);
    print(std::cout, result);
}