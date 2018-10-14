//
// Created by Jack on 14/10/2018.
//

#ifndef POLYSOLVER_EQUATION_H
#define POLYSOLVER_EQUATION_H

#include <map>

class Equation {
    std::map<int, int> terms;

    Equation* derivative{};

public:

    Equation() = default;

    explicit Equation(std::map<int, int> terms);

    ~Equation();

    Equation* add_term(int power, int coeff);

    void print_equation();

    void calculate_derivative();

    Equation* get_derivative();

    double solve(double tol, double x_min, double x_max);

    double eval(double x);
};


#endif //POLYSOLVER_EQUATION_H
