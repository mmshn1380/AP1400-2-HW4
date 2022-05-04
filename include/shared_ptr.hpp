
template <typename T>
SharedPtr<T>::SharedPtr(T* t)
{
    buffer = t;
    counter = new int { 1 };
}

template <typename T, typename... U>
SharedPtr<T> make_shared(U&&... args)
{
    return SharedPtr<T>(new T(std::forward<U>(args)...));
}

template <typename T>
SharedPtr<T>::SharedPtr()
{
    buffer = nullptr;
    counter = new int { 0 };
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    (*counter)--;
    if (*counter == 0) {
        delete buffer;
        buffer = nullptr;
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T>& shared_Ptr): buffer { shared_Ptr.buffer } , counter { shared_Ptr.counter }
{
    (*counter)++;
}

template <typename T>
SharedPtr<T> SharedPtr<T>::operator=(const SharedPtr<T>& shared_Ptr)
{
    if (this == &shared_Ptr)
        return *this;
    delete counter;
    delete buffer;
    (*counter)++;
    buffer = shared_Ptr.buffer;
    counter = shared_Ptr.counter;
    return *this;
}

template <typename T>
int SharedPtr<T>::use_count()
{
    return *counter;
}

template <typename T>
T* SharedPtr<T>::get()
{
    return buffer;
}

template <typename T>
T& SharedPtr<T>::operator*()
{
    return *buffer;
}

template <typename T>
T* SharedPtr<T>::operator->()
{
    return buffer;
}

template <typename T>
void SharedPtr<T>::reset()
{
    delete buffer;
    buffer = nullptr;
    *counter = 0;
}

template <typename T>
void SharedPtr<T>::reset(T* t)
{
    delete buffer;
    buffer = t;
    *counter = 1;
}

template <typename T>
SharedPtr<T>::operator bool() const
{
    if (buffer == nullptr)
        return false;
    else
        return true;
}