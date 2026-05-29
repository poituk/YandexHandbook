#include "address.h"
#include <iostream>
#include <string>

int main() {
    std::string line;
    Address* address =  new Address();
    while (std::getline(std::cin, line)) {
        Address address;
        try {
            Parse(line, &address);
            Unify(&address);
            std::cout << Format(address) << "\n";
        } catch (...) {
            std::cout << "exception\n";
        }
    }
    delete address;
}