//Exercise 9.25: In the program on page 349 that erased a range of
//elements, what happens if elem1 and elem2 are equal? What if elem2 or
//both elem1 and elem2 are the off-the-end iterator?

/*
 * Answer:
 * If elem1 and elem2 are equal then erase will only remove the one element that they both point to.
 * If elem1 or elem2 or both are the off the end iterator then it will be undefined behaviour since it's out of
 * the containers scope
 */
