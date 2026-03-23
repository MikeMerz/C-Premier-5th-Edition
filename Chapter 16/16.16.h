//Exercise 16.16: Rewrite the StrVec class (§ 13.5, p. 526) as a template
//named Vec.

#include <string>
#include <memory>
template <typename Type>
class Vec
{
    friend bool operator==(const Vec& lhs, const Vec& rhs);
    friend bool operator!=(const Vec& lhs, const Vec& rhs);
    friend bool operator< (const Vec& lhs, const Vec &rhs);
    friend bool operator<=(const Vec& lhs, const Vec &rhs);
    friend bool operator>(const Vec& lhs, const Vec &rhs);
    friend bool operator>=(const Vec& lhs, const Vec &rhs);
public:
    Vec(): elements(nullptr), first_free(nullptr), last(nullptr){};
    Vec(std::initializer_list<Type>);
    Vec(const Vec &vec);
    Vec(Vec &&vec) noexcept;
    Vec& operator=(const Vec& other);
    Vec& operator=(Vec&&) noexcept;
    ~Vec();
    void push_back(const Type&);
    void reserve(size_t cap);
    void resize(size_t size);
    void resize(size_t size, const Type& vec);
    Type *begin() const {return elements;}
    Type *end() const {return first_free;};
    size_t size() const{return first_free-elements;};
    size_t capacity() const{return last-elements;};


private:
    std::allocator<Type> alloc;
    void check_n_alloc()
    {
        if(size() == capacity())
            reallocate();
    }
    std::pair<Type*,Type*> alloc_n_copy(const Type*,const Type*);
    void free();
    void reallocate();
    void expandStrVec(size_t size, const Type &str);
    void decreaseStrVec();
    Type *elements;
    Type *first_free;
    Type *last;

};
template <typename Type>
bool operator==(const Vec<Type>& lhs, const Vec<Type>& rhs);
template <typename Type>
bool operator!=(const Vec<Type>& lhs, const Vec<Type>& rhs);
