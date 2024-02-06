//Exercise 9.31: The program on page 354 to remove even-valued elements
//and duplicate odd ones will not work on a list or forward_list. Why?
//Revise the program so that it works on these types as well.

#include <vector>
#include <list>
#include <forward_list>

/*
 * Answer:
 * It won't work on list or forward_list since list doesnt support iterator arithmetic and forward_list
 * doesnt support insert(it uses insert_after)
 */

void changeForList(std::list<int> &ch)
{
    auto iter = ch.begin();
    while (iter != ch.end()) {
        if (*iter % 2) {
            iter = ch.insert(iter, *iter);
            //iter += 2;
            ++iter;
            ++iter;
        } else
            iter = ch.erase(iter);
    }
}

void changeForForwardList(std::forward_list<int> &ch)
{
    auto iter = ch.begin();
    auto prev = ch.before_begin();
    while (iter != ch.end()) {
        if (*iter % 2) {
            iter = ch.insert_after(prev, *iter);
            ++iter;
            ++prev;
        } else
            iter = ch.erase_after(prev);
    }
}