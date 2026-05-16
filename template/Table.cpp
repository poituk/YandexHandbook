#include <vector>
#include <iostream>

template<typename T>
class Table
{
private:
    std::vector<std::vector<T>> table;
public:
    Table() = default;
    Table(size_t n_, size_t m_);
    ~Table() = default;

    void resize(size_t n_, size_t m_);
    std::pair<size_t, size_t> size() const;
    std::vector<T>& operator[](size_t i);
    const std::vector<T>& operator[](size_t i) const;
};

template<typename T>
Table<T>::Table(size_t n_, size_t m_) {
    table.assign(n_, std::vector<T>(m_));
}

template<typename T>
void Table<T>::resize(size_t n_, size_t m_) {
    for (size_t i = 0; i < n_; i++) {
        if(table.size() < n_) {
            table.push_back(std::vector<T>(m_));
        }
        table[i].resize(m_);
    }
    while(table.size() != n_)
        table.pop_back();
}

template<typename T>
std::pair<size_t, size_t> Table<T>::size() const {
    return {table.size(), table[0].size()};
}

template<typename T>
std::vector<T>& Table<T>::operator[] (size_t i) {
    return table[i];
}
template<typename T>
const std::vector<T>& Table<T>::operator[] (size_t i) const {
    return table[i];
}

int main() {
    Table<int> c(3, 4);
    c[0][0] = 1;
    std::cout << c[0][0] << "\n";
}