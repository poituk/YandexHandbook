#include <exception>
#include <functional>
#include <optional>
#include <chrono>
#include <thread>    

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func,
                                  int retryCount, int sleepTime, bool throwLast) {
    while (retryCount--) {
        try
        {
            return func();
        } catch (const Exception&)  {
            Sleep(sleepTime);
        }
    }

    try {
        return func();
    } catch(const Exception&) {
        if (throwLast) {
            throw;
        }
    }
    return std::nullopt;
    
}