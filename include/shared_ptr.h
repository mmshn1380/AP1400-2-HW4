#ifndef SHARED_PTR
#define SHARED_PTR
#include <iostream>
#include <utility>

template <typename T>
class SharedPtr {
public:
    SharedPtr(T* t);
    SharedPtr();
    ~SharedPtr();
    SharedPtr(const SharedPtr<T>& shared_Ptr);
    SharedPtr<T> operator=(const SharedPtr<T>& shared_Ptr);
    int use_count();
    void reset();
    void reset(T* t);
    T* get();
    T& operator*();
    T* operator->();
    operator bool() const;

private:
    T* buffer;
    int* counter;
};

template <typename T, typename... U>
SharedPtr<T> make_shared(U&&... args);
#include "shared_ptr.hpp"
#endif // SHARED_PTR