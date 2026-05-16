#include <cstddef>
#include <iostream>
#include <vector>
#include <stdexcept>


template <typename T>
class Deque {
private:
    std::vector<T> head, tail;

public:
    bool Empty() const;

    size_t Size() const;

    void Clear();

    const T& operator [] (size_t i) const;

    T& operator [] (size_t i);

    const T& At(size_t i) const;  // throws std::out_of_range on incorrect index

    T& At(size_t i);  // throws std::out_of_range on incorrect index

    const T& Front() const;

    T& Front();

    const T& Back() const;

    T& Back();

    void PushFront(const T& elem);

    void PushBack(const T& elem);
};

template<typename T>
bool Deque<T>::Empty() const {
    return (head.empty() and tail.empty());
}

template<typename T>
size_t Deque<T>::Size() const {
    return (head.size() + tail.size());
}

template<typename T>
void Deque<T>::Clear() {
    head.clear();
    tail.clear();
}

template<typename T>
const T& Deque<T>::operator[] (size_t i) const {
    if (i < head.size()) {
        return head[head.size() - i - 1];
    } else {
        return tail[i - head.size()];
    }
}

template<typename T>
T& Deque<T>::operator[] (size_t i) {
    if (i < head.size()) {
        return head[head.size() - i - 1];
    } else {
        return tail[i - head.size()];
    }
}

template<typename T>
const T& Deque<T>::At (size_t i) const {
    if(i >= head.size() + tail.size()) {
        throw std::out_of_range("incorrect index");
    }
    if (i < head.size()) {
        return head[i];
    } else {
        return tail[i - head.size()];
    }
}

template<typename T>
T& Deque<T>::At (size_t i) {
    if(i >= head.size() + tail.size()) {
        throw std::out_of_range("incorrect index");
    }
    if (i < head.size()) {
        return head[i];
    } else {
        return tail[i - head.size()];
    }
}

template<typename T>
const T& Deque<T>::Front() const {
    if (!head.empty())
        return head.back();
    return tail.front();
}


template<typename T>
T& Deque<T>::Front() {
    if (!head.empty())
        return head.back();
    return tail.front();
}


template<typename T>
const T& Deque<T>::Back() const {
    if (tail.empty())
        return head.front();
    return tail.back();
}


template<typename T>
T& Deque<T>::Back() {
    if (tail.empty())
        return head.front();
    return tail.back();
}

template<typename T>
void Deque<T>::PushFront(const T& elem) {
    head.push_back(elem);
}


template<typename T>
void Deque<T>::PushBack(const T& elem) {
    tail.push_back(elem);
}

int main() {
    Deque<int> c;
    c.PushBack(12);
    std::cout << c.Front();
}