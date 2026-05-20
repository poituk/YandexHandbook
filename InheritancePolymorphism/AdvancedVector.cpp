#include <stdexcept>
#include <vector>
#include <iostream>

template<typename T>
class AdvancedVector : public std::vector<T>
{
public:
    AdvancedVector() = default;

    template<typename Iterator>
    AdvancedVector(Iterator first, Iterator second) : std::vector<T>(first, second) {}

    T& operator [] (int i) {
        if (i < 0) {
            i = static_cast<int>(this->size()) + i;
        }
        if (i < 0 || i >= static_cast<int>(this->size())) {
            throw std::out_of_range("Index out of range");
        }
        return this->at(i);
    }

    const T& operator [] (int i) const {
        if (i < 0) {
            i = static_cast<int>(this->size()) + i;
        }
        if (i < 0 || i >= static_cast<int>(this->size())) {
            throw std::out_of_range("Index out of range");
        }
        return this->at(i);
    }
};

int main() {
    AdvancedVector<int> c;
    c.push_back(1);
    std::cout << c[-1];
}