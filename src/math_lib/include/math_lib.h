#pragma once

#include <cmath>
#include <stdexcept>

namespace MathLib
{
    template <typename T>
    T add(T a, T b)
    {
        return a + b;
    }

    template <typename T>
    T subtract(T a, T b)
    {
        return a - b;
    }

    template <typename T>
    T multiply(T a, T b)
    {
        return a * b;
    }

    template <typename T>
    T divide(T a, T b)
    {
        if (b == 0)
        {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return a / b;
    }

    bool isEqual(double a, double b, double tolerance = 1e-6);

    template <typename T>
    double sqrt(T a)
    {
        if (a < 0)
            throw std::invalid_argument("Cannot get the square root of a negative number");
        if (a == 0)
            return 0.0;

        const double value = static_cast<double>(a);
        double estimate = value;

        for (int i = 0; i < 1000; ++i)
        {
            const double next = 0.5 * (estimate + (value / estimate));
            if (isEqual(next, estimate, 1e-12))
                return next;
            estimate = next;
        }

        return estimate;
    }

    bool isPrime(int n);
	int leastCommonMultiple(int a, int b);
    int GCD(int a, int b);
}
