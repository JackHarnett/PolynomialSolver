#include <iostream>
#include "Equation.h"
#include <string>

int main() {
    auto eq = std::make_unique<Equation>();
    eq->add_term(3, 2)->add_term(0, 10);

    eq->print_equation();

    eq->calculate_derivative();
    eq->get_derivative()->print_equation();


    double sln = eq->solve(0.000001, -15, 15);

    std::cout << "Solution: " << sln << std::endl;

    return 0;
}