//
// Created by Jack on 14/10/2018.
//


#include "Equation.h"
#include <iostream>
#include <cmath>


Equation::Equation(std::map<int, int> terms) : terms(terms){}

Equation::~Equation() {
    delete derivative;
}

Equation* Equation::add_term(int power, int coeff) {
    terms.insert(std::make_pair(power, coeff));
    return this;
}

void Equation::print_equation() {
    std::cout << "Equation: ";

    int counter = 0;
    for (auto &term : terms) {
        std::cout << term.second << "X^" << term.first;
        ++counter;

        if(counter != terms.size()) {
            std::cout << " + ";
        }
    }

    std::cout << std::endl;
}

void Equation::calculate_derivative() {
    std::map<int, int> diff_terms;

    for(auto term : terms) {
        if(term.first != 0) {
            diff_terms.insert(std::make_pair(term.first-1, term.first*term.second));
        }
    }

    derivative = new Equation(diff_terms);
}

Equation *Equation::get_derivative() {
    return derivative;
}

double Equation::eval(double x) {
    double total=0;
    for(auto term : terms) {
        total += term.second * pow(x, term.first);
    }

    return total;
}

double Equation::solve(double tol, double x_min, double x_max) {

    if(terms.find(0) == terms.end()) {
        return 0;
    } else {
        if(terms.find(0)->second > 0) {
            std::cout << "Has no real roots" << std::endl;
            return 0;
        }
    }

    double est = 0.5 * (x_max + x_min);

    if(est == 0) {
        est=1;
    }

    while(abs(eval(est)) > tol) {
        est = est - (eval(est) / derivative->eval(est));
    }

    return est;
}



