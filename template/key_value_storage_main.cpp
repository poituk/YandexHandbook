#include "key_value_storage.cpp"

#include <string>

int main() {
    KeyValueStorage<std::string, int> kv;
    kv.Insert("hello", 42);
    kv.Insert("bye", -13);
    int value = 123;
    auto res = kv.Find("wrong", &value);  // должно вернуться false, а value не должен меняться
    res = kv.Find("bye", &value);  // должно вернуться true, в value должно быть -13
    res = kv.Find("hello", nullptr);  // должно вернуться true
}