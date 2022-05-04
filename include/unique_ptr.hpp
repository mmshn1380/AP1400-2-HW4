
template <typename T>
UniquePtr<T>::UniquePtr(T* t)
{
    buffer = t;
}

template <typename T, typename... U>
UniquePtr<T> make_unique(U&&... args)
{
    return UniquePtr<T>(new T(std::forward<U>(args)...));
}

template <typename T>
UniquePtr<T>::UniquePtr()
{
    buffer = nullptr;
}

template <typename T>
UniquePtr<T>::~UniquePtr()
{
    if (buffer) {
        delete buffer;
        buffer = nullptr;
    }
}

template <typename T>
T* UniquePtr<T>::get()
{
    return buffer;
}

template <typename T>
void UniquePtr<T>::reset()
{
    delete buffer;
    buffer = nullptr;
}

template <typename T>
void UniquePtr<T>::reset(T* t)
{
    delete buffer;
    buffer = t;
}

template <typename T>
T* UniquePtr<T>::release()
{
    T* Ptr { buffer };
    buffer = nullptr;
    return Ptr;
}

template <typename T>
T& UniquePtr<T>::operator*()
{
    return *buffer;
}

template <typename T>
T* UniquePtr<T>::operator->()
{
    return buffer;
}

template <typename T>
UniquePtr<T>::operator bool() const
{
    if (buffer == nullptr)
        return false;
    else
        return true;
}