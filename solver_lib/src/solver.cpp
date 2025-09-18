#include "solver.hpp"

double solve_equation(double a, double b) {
    if (a == 0) {
        return 0;
    }
    return -b / a;
}
