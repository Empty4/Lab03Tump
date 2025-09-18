#include "formatter_ex.hpp"
#include "solver.hpp"
#include <iostream>

int main() {
    double a = 2.0, b = 4.0;
    double result = solve_equation(a, b);
    
    std::string message = "Solution: x = " + std::to_string(result);
    std::string formatted = formatter_ex::format(message);
    
    std::cout << formatted << std::endl;
    return 0;
}
