#include <cstddef>

//Exercise 16.28: Write your own versions of shared_ptr and
//unique_ptr.
//Exercise 16.29: Revise your Blob class to use your version of
//shared_ptr rather than the library version.
//Exercise 16.30: Rerun some of your programs to verify your shared_ptr
//and revised Blob classes. (Note: Implementing the weak_ptr type is
//beyond the scope of this Primer, so you will not be able to use the BlobPtr
//class with your revised Blob.)
//Exercise 16.31: Explain how the compiler might inline the call to the deleter
//if we used DebugDelete with unique_ptr.
//TODO: STILL FINISH ME PRONTOOOOOOOOOO
template <typename T>
class shared_ptr_custom
{
    shared_ptr_custom(): pointer(nullptr),refCount(new std::size_t(1)){};
    shared_ptr_custom(const shared_ptr_custom<T>& other): pointer(other.pointer),refCount(other.refCount)
    {
        ++(*refCount);
    }
    explicit shared_ptr_custom(T* other): pointer(other),refCount(new std::size_t(1)){};
    shared_ptr_custom(shared_ptr_custom<T>&& other): pointer(other.pointer),refCount(other.refCount)
    {
        other.pointer = nullptr;
        other.refCount = nullptr;
    };
    void make_shared()
    {

    }
    T* operator->() const
    {
      return &*pointer;
    }
    T& operator*() const
    {
        return *pointer;
    }
    T* get() const
    {
        return pointer;
    }
    void reset(T* point)
    {
        --(*refCount);
        if(!(*refCount))
        {
            delete refCount;
            delete pointer;
        }
    }
    void swap()
    {

    }
    void use_count()
    {

    }
    void owner_before()
    {

    }
    void unique()
    {

    }
private:
    T* pointer;
    std::size_t* refCount;
};