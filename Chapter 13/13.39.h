//Exercise 13.39: Write your own version of StrVec, including versions of
//reserve, capacity (§ 9.4, p. 356), and resize (§ 9.3.5, p. 352).

//Exercise 13.40: Add a constructor that takes an
//initializer_list<string> to your StrVec class.


#include <string>
#include <memory>

class StrVec
{
public:
    StrVec():elements(nullptr), first_free(nullptr), last(nullptr){};
    StrVec(std::initializer_list<std::string>);
    StrVec(const StrVec &vec);
    StrVec& operator=(const StrVec& other);
    ~StrVec();
    void push_back(const std::string&);
    void reserve(size_t cap);
    void resize(size_t size);
    void resize(size_t size, const std::string& vec);
    std::string *begin() const {return elements;}
    std::string *end() const {return first_free;};
    size_t size() const{return first_free-elements;};
    size_t capacity() const{return last-elements;};


private:
    std::allocator<std::string> alloc;
    void check_n_alloc()
    {
        if(size() == capacity())
            reallocate();
    }
    std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);
    void free();
    void reallocate();
    void expandStrVec(size_t size, const std::string &str);
    void decreaseStrVec();
    std::string *elements;
    std::string *first_free;
    std::string *last;

};
