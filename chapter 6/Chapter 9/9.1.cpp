//Exercise 9.1: Which is the most appropriate—a vector, a deque, or a
//list—for the following program tasks? Explain the rationale for your choice.
//If there is no reason to prefer one or another container, explain why not.
//(a) Read a fixed number of words, inserting them in the container
//alphabetically as they are entered.
//(b) Read an unknown number of words. Always insert new words at the
//back. Remove the next value from the front.
//(c) Read an unknown number of integers from a file. Sort the numbers and
//then print them to standard output.

/*
 * Answer:
 * a ---> List will be most appropriate since it guarantees inserting at constant time to the middle and to both ends and since
 * the words needs to be sorted alphabetically it will have to support efficient inserting at  the middle.
 * b ---> Deque will be most appropriate since it guarantees insert/deleting at the front/back at constant time.
 * c ---> There is no reason to prefer one or the other, since with list we can sort while we are reading the integers and  then print them
 * and with vector and deque we can read all of the integers and then sort them
 */
