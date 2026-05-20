#include <iostream>
#include <string>
#include <vector>

class Serializer
{
public:
    Serializer() = default;
    virtual ~Serializer() = default;
    virtual void BeginArray() = 0;
    virtual void AddArrayItem(const std::string &s) = 0;
    virtual void EndArray() = 0;
};

class JsonSerializer : public Serializer
{
private:
    std::vector<bool> last;
public:
    JsonSerializer() {
        last.push_back(0);
    }
    void BeginArray() override {
        
        if(!last.back()) {
            std::cout << "[";
        }
        else
        {
            std::cout << ",[";
        }
        last.push_back(0);
    }
    void AddArrayItem(const std::string &s) override {
        if(!last.back()) {
            std::cout << "\"" << s << "\"";
        }
        else
        {
            std::cout << ",\"" << s << "\"";
        }
        last.back() = 1;
    }

    void EndArray() override {
        std::cout << "]";
        last.pop_back();
        if(!last.empty()) last.back() = 1;
    }
};
