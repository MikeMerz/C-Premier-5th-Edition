//Exercise 9.22: Assuming iv is a vector of ints, what is wrong with the
//following program? How might you correct the problem(s)?
//vector<int>::iterator iter = iv.begin(),
//mid = iv.begin() + iv.size()/2;
//while (iter != mid)
//if (*iter == some_val)
//iv.insert(iter, 2 * some_val);

/*
 * Answer:
 * The iterator might get invalidated since we are inserting new elements and since we are inserting at the position
 * of iter the while will not end since we are not advancing iter.
 */
