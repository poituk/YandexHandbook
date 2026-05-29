#include <stdexcept>
#include <optional>
#include <map>
#include <memory>

template <typename Key1, typename Key2, typename Value>
class BiMap {
private:
    std::map<Key1, std::shared_ptr<Value>> firstKey;
    std::map<Key2, std::shared_ptr<Value>> secondKey;
    
public:
    void Insert(const std::optional<Key1>& key1, 
                const std::optional<Key2>& key2, 
                const Value& value) {
        if (!key1.has_value() && !key2.has_value()) {
            throw std::invalid_argument("some text");
        }
        
        if (key1.has_value() && firstKey.find(key1.value()) != firstKey.end()) {
            throw std::invalid_argument("some text");
        }
        
        if (key2.has_value() && secondKey.find(key2.value()) != secondKey.end()) {
            throw std::invalid_argument("some text");
        }
        
        auto ptr = std::make_shared<Value>(value);
        if (key1.has_value()) {
            firstKey[key1.value()] = ptr;
        }
        if (key2.has_value()) {
            secondKey[key2.value()] = ptr;
        }
    }

    Value& GetByPrimaryKey(const Key1& key) {
        auto it = firstKey.find(key);
        if (it == firstKey.end()) {
            throw std::out_of_range("some text");
        }
        return *(it->second);
    }
    
    const Value& GetByPrimaryKey(const Key1& key) const {
        auto it = firstKey.find(key);
        if (it == firstKey.end()) {
            throw std::out_of_range("some text");
        }
        return *(it->second);
    }

    Value& GetBySecondaryKey(const Key2& key) {
        auto it = secondKey.find(key);
        if (it == secondKey.end()) {
            throw std::out_of_range("some text");
        }
        return *(it->second);
    }
    
    const Value& GetBySecondaryKey(const Key2& key) const {
        auto it = secondKey.find(key);
        if (it == secondKey.end()) {
            throw std::out_of_range("some text");
        }
        return *(it->second);
    }
};