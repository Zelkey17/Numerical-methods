//
// Created by ash on 28.05.23.
//

#include "utils/functionaluty.h"
#include <cmath>

/// Площадь методом трапеций от a до b с разделением на n частей
double trap_integral(func(f), double a, double b, int n) {
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (f(a + (b - a) / n * i) + f(a + (b - a) / n * (i + 1))) / 2 * (b - a) / n;
    }
    return ans;
}


/// Итоговая площадь методом трапеций от a до b с погрештостью eps
double trap_method(func(f), double a, double b, double eps) {
    int n = 1;
    double now = trap_integral(f, a, b, n);
    double next = trap_integral(f, a, b, n * 2);
    while (std::abs(now - next) / 3 > eps) { //правило Рунге
        n *= 2;
        now = next;
        next = trap_integral(f, a, b, n * 2);
    }
    return next;
}


/// Площадь методом левых прямоугольников от a до b с разделением на n частей
double left_integral(func(f), double a, double b, int n) {
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += f(a + (b - a) * i / n) * (b - a) / n;
    }
    return ans;
}


/// Итоговая площадь методом левых прямоугольников от a до b с погрештостью eps
double left_method(func(f), double a, double b, double eps) {
    int n = 1;
    double now = left_integral(f, a, b, n);
    double next = left_integral(f, a, b, n * 2);
    while (std::abs(now - next) > eps) { //правило Рунге
        n *= 2;
        now = next;
        next = left_integral(f, a, b, n * 2);
    }
    return next;
}


/// Площадь методом центральных прямоугольников от a до b с разделением на n частей
double center_integral(func(f), double a, double b, int n) {
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += f(a + (b - a) * i / n + (b - a) / 2 / n) * (b - a) / n;
    }
    return ans;
}


/// Итоговая площадь методом центральных прямоугольников от a до b с погрештостью eps
double center_method(func(f), double a, double b, double eps) {
    int n = 1;
    double now = center_integral(f, a, b, n);
    double next = center_integral(f, a, b, n * 2);
    while (std::abs(now - next) / 3 > eps) { //правило Рунге
        n *= 2;
        now = next;
        next = center_integral(f, a, b, n * 2);
    }
    return next;
}


/// Площадь методом симпсона от a до b с разделением на n частей
double simpson_integral(func(f), double a, double b, int n) {
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ((b - a) / 6 / n) *
               (f(a + (b - a) / n * i) + f(a + (b - a) / n * (i + 1)) + 4 * f(a + (b - a) * i / n + (b - a) / 2 / n));
    }
    return ans;
}


/// Итоговая площадь методом симпсона от a до b с погрештостью eps
double simpson_method(func(f), double a, double b, double eps) {
    int n = 1;
    double now = simpson_integral(f, a, b, n);
    double next = simpson_integral(f, a, b, n * 2);
    while (std::abs(now - next) / 15 > eps) { //правило Рунге
        n *= 2;
        now = next;
        next = simpson_integral(f, a, b, n * 2);
    }
    return next;
}
