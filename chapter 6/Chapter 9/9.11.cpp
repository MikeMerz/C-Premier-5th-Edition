//Exercise 9.11: Show an example of each of the six ways to create and
//initialize a vector. Explain what values each vector contains.

/*
 * Answer:
 * std::vector<int> v1; ---> Empty Vector
 * std::vector<int> v2 = {40,7,8,10} ---> Holds 40,7,8,10
 * std::vector<int> v3 = v2; ---> Holds the same
 * std::vector<int> v4(v2); ---> 40,7,8,10
 * std::vector<int> v5(v2.begin(),v2.end()) ---> 40,7,8,10
 * std::vector<int> v6(3,10) ---> 10,10,10
 */
