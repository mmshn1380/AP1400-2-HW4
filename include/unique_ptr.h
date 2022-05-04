#ifndef UNIQUE_PTR
#define UNIQUE_PTR
#include <iostream>
#include <memory>
#include <utility>

template <typename T>
class UniquePtr {
public:
    UniquePtr(T* t);
    UniquePtr();
    ~UniquePtr();
    UniquePtr(const UniquePtr<T>& uniquePtr) = delete;
    UniquePtr<T>& operator=(const UniquePtr<T>& uniquePtr) = delete;
    void reset();
    void reset(T* t);
    T* release();
    T* get();
    T& operator*();
    T* operator->();
    operator bool() const;

private:
    T* buffer;
};

template <typename T, typename... U>
UniquePtr<T> make_unique(U&&... args);
#include "unique_ptr.hpp"
#endif // UNIQUE_PTR