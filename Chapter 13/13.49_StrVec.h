//Exercise 13.49: Add a move constructor and move-assignment operator to
//your StrVec, String, and Message classes.


#include <string>
#include <memory>

class StrVec
{
public:
    StrVec():elements(nullptr), first_free(nullptr), last(nullptr){};
    StrVec(std::initializer_list<std::string>);
    StrVec(const StrVec &vec);
    StrVec(StrVec &&vec) noexcept;
    StrVec& operator=(const StrVec& other);
    StrVec& operator=(StrVec&&) noexcept;
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
