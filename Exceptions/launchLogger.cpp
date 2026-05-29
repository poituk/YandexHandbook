#include <iostream>
#include <exception>
#include "LoggerGuard.cpp"

void SomeFunction() {
    throw std::exception();
}

int Function() {
    LoggerGuard logger("Function completed");

    int value = 1;
    try {
        if (value == 0) {
            return value;
        }
        SomeFunction();
        if (value == 0)
        {
            return value;
        }
    } catch (...) {
        throw;  // throws the exception further.
    }

    return value;
}
int main() {
    Function();
}