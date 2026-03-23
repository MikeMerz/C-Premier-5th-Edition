//Exercise 16.58: Write the emplace_back function for your StrVec class
//and for the Vec class that you wrote for the exercises in § 16.1.2 (p. 668).
//Answer:
//template<typename... Args> void emplace_back(Args&&... args)
// {
// check_n_alloc();
// alloc.construct(first_free++,std::forward<Args>(args)...);
// }
//Exercise 16.59: Assuming s is a string, explain
//svec.emplace_back(s).
//Answer:
//s is lvalue and thus Args will be deduced as string& and Args&& will be deduced as string& && which by refrence collapsing will
//become string&&, then, svec.emplace_back(string&) will be instantiated and forward<string&> will be called which will in turn call
//the copy constructor.
//Exercise 16.60: Explain how make_shared (§ 12.1.1, p. 451) works.
//
//Answer:
//First, make_shared is a variadic templated as follows:
//template<class T, typename... Args>
//shared_ptr<T> make_shared(Args&&... args) ---> it first allocated memory for the control block, then it forwards
//args to corresponding constructor which is then wrapped shared_ptr, it also updates the inside ref count for that object.
//
//Exercise 16.61: Define your own version of make_shared.
//
//Answer:
//template<class T, typename... Args>
//shared_ptr<T> make_shared(Args&&... args)
//{
//  return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
//}


