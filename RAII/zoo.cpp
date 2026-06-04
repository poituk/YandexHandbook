#include <iostream>
#include <stdexcept>
#include <vector>

#include "animals.h"
#include <memory>

using Zoo = std::vector<std::unique_ptr<Animal>>;

Zoo CreateZoo() {
    Zoo zoo;
    std::string word;
    while (std::cin >> word) {
        if (word == "Tiger") {
            std::unique_ptr<Tiger> t = std::make_unique<Tiger>();
            zoo.push_back(std::move(t));
        } else if (word == "Wolf") {
            std::unique_ptr<Wolf> w = std::make_unique<Wolf>();
            zoo.push_back(std::move(w));
        } else if (word == "Fox") {
            std::unique_ptr<Fox> f = std::make_unique<Fox>();
            zoo.push_back(std::move(f));
        } else if(word == "end") {
            return zoo;
        }
        else
            throw std::runtime_error("Unknown animal!");
    }
    return zoo;
}

void Process(const Zoo& zoo) {
    for (const auto& animal : zoo) {
        std::cout << animal->Voice() << "\n";
    }
}
int main() {
    Process(CreateZoo());
}