//Exercise 9.39: Explain what the following program fragment does:
//vector<string> svec;
//svec.reserve(1024);
//string word;
//while (cin >> word)
//svec.push_back(word);
//svec.resize(svec.size()+svec.size()/2);

/*
 * Answer:
 * The program will allocate memory for 1024 elements, then it will read the users input and push it to the vector
 * after the loop ends the size will grow, if the size is larger then the reserved size the capacity will grow otherwise it will not change.
 */