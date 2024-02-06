//Exercise 9.6: What is wrong with the following program? How might you
//correct it?

//list<int> lst1;
//list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
//while (iter1 < iter2) /* ... */

/*
 * Answer:
 * Iterator don't support arithmetic operations so the condition of the while loop should be changed to iter1 != iter2.
 */
