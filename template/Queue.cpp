#include <deque>
#include <iostream>

template <typename T, typename Container = std::deque<T>>
class Queue
{
private:
    Container queue;
public:
    using const_iterator = decltype(queue.cbegin());

    Queue() = default;
    ~Queue() = default;

    const T& front() const {
        return queue.front();
    }

    T& front() {
        return queue.front();
    }

    void pop() {
        queue.pop_front();
    }

    void push(T value) {
        queue.push_back(value);
    }

    size_t size() const {
        return queue.size();
    }

    bool empty() const {
        return !queue.size();
    }

    const_iterator begin() const {
        return queue.cbegin();
    }

    const_iterator end() const {
        return queue.cend();        
    }

    template<typename T2>
    bool operator ==(const Queue<T2>& other) const {
        if (queue.size() != other.size())
            return false;

        auto it1 = (*this).begin();
        auto it2 = other.begin();

        while(it1 != (*this).end()) {
            if(*it1 != *it2)
                return false;
            ++it1;
            ++it2;
        }
        return true;
    }

    template<typename T2>
    bool operator !=(const Queue<T2>& other) const {
        return !((*this) == other);
    }
};


int main() {
    Queue<int> c1;
    Queue<double> c2;
    c1.push(1);
    c2.push(1.0);
    std::cout << (c1 == c2) << "\n";
}