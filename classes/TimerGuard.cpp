#include <ostream>
#include <chrono>
#include <iostream>

class TimerGuard{
    private:
        std::string message;
        std::ostream &out;
        std::chrono::time_point<std::chrono::high_resolution_clock> start;

    public:
        TimerGuard(std::string _message = "", std::ostream& _out = std::cout) : message(_message), out(_out) {
            start = std::chrono::high_resolution_clock::now();
        }

        ~TimerGuard() {
            std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
            out << message << " " << diff.count() << "\n";
        }
};