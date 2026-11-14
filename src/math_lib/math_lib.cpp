#include "math_lib.h"
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <limits>

namespace MathLib
{
    bool isEqual(double a, double b, double tolerance)
    {
        return std::abs(a - b) <= tolerance;
    }

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int leastCommonMultiple(int a, int b)
    {
        int lcm = 1;
        int maxNum = std::max(a, b);
        for (int i = maxNum; i <= a * b; i += maxNum)
        {
            if (i % a == 0 && i % b == 0)
            {
                lcm = i;
                break;
            }
        }
        return lcm;
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

    double thirdAngle(double a, double b)
    {
        if (a <= 0 || b <= 0 || a + b >= 180)
            throw std::invalid_argument("Invalid triangle angles");
        return 180.0 - a - b;
    }
}
