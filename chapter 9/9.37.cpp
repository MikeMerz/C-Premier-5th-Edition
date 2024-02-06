//Exercise 9.37: Why don’t list or array have a capacity member?

/*
 * Answer:
 * Array doesn't have a capacity member since we set it's capcity when declaring and there is no reallocation
 * since the capacity of the array can not be changed.
 * List's implementaion is using links and thus we dont hold all of it's elements but each time we store the pointer and
 * no reallocation happnes.
 */
