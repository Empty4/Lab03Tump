#include "formatter_ex.hpp"
#include <iostream>

int main() {
    std::string message = "hello, world!";
    std::string formatted = formatter_ex::format(message);
    std::cout << formatted << std::endl;
    return 0;
}
