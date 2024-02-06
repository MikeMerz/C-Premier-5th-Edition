//Exercise 9.40: If the program in the previous exercise reads 256 words,
//what is its likely capacity after it is resized? What if it reads 512? 1,000?
//1,048?

/*
 * Answer:
 * After the resize for 256 words capacity will be 256+(256/2) = 384 and the capacity will remain unchanged, the same for
 * 512 and 1000, only for 1048 the vector will be reallocated and the new capacity will be determined by the implementation.
 */
