#include "math_lib.h"
#include <cmath>
#include <algorithm>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return std::fabs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0) return false;

        for (int i = 3; i * i <= n; i += 2)
            if (n % i == 0) return false;

        return true;
    }

    int GCD(int a, int b)
    {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0)
        {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    int leastCommonMultiple(int a, int b)
    {
        if (a == 0 || b == 0) return 0;
        int gcd = GCD(a, b);
        return std::abs((a / gcd) * b);
    }
}
