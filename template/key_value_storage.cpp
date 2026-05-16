#include <unordered_map>

template <typename Key, typename Value>
class KeyValueStorage {
private:
      std::unordered_map<Key, Value> data;

public:
    void Insert(const Key& key, const Value& value) {
        data[key] = value;
    }

    void Remove(const Key& key) {
        data.erase(key);
    }

    bool Find(const Key& key, Value* const value = nullptr) const;
};

template <typename Key, typename Value>
bool KeyValueStorage<Key, Value>::Find(const Key& key, Value* value) const {
    auto it = data.find(key);
    if (it != data.end()) {
        if (value == nullptr)
            return true;
        *value = it->second;
        return true;
    }
    return false;
}