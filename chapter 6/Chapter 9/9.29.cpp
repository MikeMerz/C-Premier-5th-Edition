//Exercise 9.29: Given that vec holds 25 elements, what does
//vec.resize(100) do? What if we next wrote vec.resize(10)?

/*
 * Answer:
 * Given vec has 25 elements and we are resizing to 100, it will create 75 value initialized instances
 * of the same element to the back, if afterward we resize to 10 then we will discard 90 elements and we will
 * be left with only 10 elements of the original 25 elements.
 */
