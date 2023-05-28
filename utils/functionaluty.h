//
// Created by ash on 28.05.23.
//

#ifndef NUMERICAL_METHODS_FUNCTIONALUTY_H
#define NUMERICAL_METHODS_FUNCTIONALUTY_H

#define func(x) double (*(x))(double)

auto derivative(double (*f)(double), double eps) {
    auto der = [f, eps](double x) {
        return (f(x + eps) - f(x)) / eps;
    };
    return der;
}


#endif //NUMERICAL_METHODS_FUNCTIONALUTY_H
