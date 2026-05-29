#include <ostream>
#include <string>
#include <iostream>

class LoggerGuard
{
private:
    std::ostream& out;
    std::string message;
public:
    LoggerGuard(const std::string& message_, std::ostream& out_ = std::cout) : out(out_), message(message_) {}
    
    ~LoggerGuard() {
        out << message << "\n";
    }
};

