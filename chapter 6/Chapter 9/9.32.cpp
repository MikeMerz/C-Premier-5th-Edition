//Exercise 9.32: In the program onpage 354 would it be legal to write the call
//to insert as follows? If not, why not?

//iter = vi.insert(iter, *iter++);

/*
 * Answer:
 * No, because * has higher precedence to the operator ++ so it will first derefrence the iterator and add to the value
 * of the iterator so using this statement will cause us to add (*iter)+1 instead of *iter.
 */