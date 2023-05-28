//
// Created by ash on 28.05.23.
//

#include "utils/functionaluty.h"
#include <cmath>


///Функция и границы
double get_hord(func(f), double a, double b) {
    return a - ((b - a) * f(a)) / (f(b) - f(a));
}

/// Функция её производная и точка к которой проводим производную
double get_kos(func(f), func(g), double x) {
    return x - f(x) / g(x);
}

double get_kos(func(f), double x, double eps) {
    return x - f(x) / derivative(f,eps)(x);
}

///Метод хорд принимает только валидные a и b так же принимает eps - точность
double hord_method(func(f), double a, double b, double eps) {
    double x = get_hord(f, a, b);
    if (f(a) * f(x) <= 0) {
        while (std::abs(x - b) > eps) {
            b = x;
            x = get_hord(f, a, b);
        }
        return b;
    } else {
        while (std::abs(x - a) > eps) {
            a = x;
            x = get_hord(f, a, b);
        }
        return a;
    }
}

///Метод косательных принимает отрезок, но определяет лишь одно значение, также принимает eps - точность
double kos_method(func(f), func(g), double a, double b, double eps) {
    double kos_a = get_kos(f, g, a);
    double kos_b = get_kos(f, g, b);
    if (kos_a > a && kos_a < b) {
        while (std::abs(kos_a - a) > eps) {
            a = kos_a;
            kos_a = get_kos(f, g, a);
        }
        return a;
    } else if (kos_b > a && kos_b < b) {
        while (std::abs(kos_b - b) > eps) {
            b = kos_b;
            kos_b = get_kos(f, g, b);
        }
        return b;
    }
}
double kos_method(func(f), double a, double b, double eps) {
    double kos_a = get_kos(f, a,eps/f(a));
    double kos_b = get_kos(f, b,eps/f(b));
    if (kos_a > a && kos_a < b) {
        while (std::abs(kos_a - a) > eps) {
            a = kos_a;
            kos_a = get_kos(f, a,eps/f(a));
        }
        return a;
    } else if (kos_b > a && kos_b < b) {
        while (std::abs(kos_b - b) > eps) {
            b = kos_b;
            kos_b = get_kos(f, b,eps/f(b));
        }
        return b;
    }
}

///Метод косательных и хорд
double mix_method(func(f), func(g), double a, double b, double eps) {
    while (std::abs(a - b) > eps) {
        double x = get_hord(f, a, b);
        if (f(a) * f(x) <= 0) {
            b = x;
        } else {
            a = x;
        }
        double kos_a = get_kos(f, g, a);
        double kos_b = get_kos(f, g, b);

        if (kos_a > a && kos_a < b) {
            a = kos_a;
        } else if (kos_b > a && kos_b < b) {
            b = kos_b;
        }
    }
    return a;
}
double mix_method(func(f), double a, double b, double eps) {
    while (std::abs(a - b) > eps) {
        double x = get_hord(f, a, b);
        if (f(a) * f(x) <= 0) {
            b = x;
        } else {
            a = x;
        }
        double kos_a = get_kos(f, a, eps/f(a));
        double kos_b = get_kos(f, b, eps/f(b));

        if (kos_a > a && kos_a < b) {
            a = kos_a;
        } else if (kos_b > a && kos_b < b) {
            b = kos_b;
        }
    }
    return a;
}


int main() {

}
