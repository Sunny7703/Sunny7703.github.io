#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double p, q, r, s, t, u;

double f(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main()
{
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        double f0 = f(0), f1 = f(1);
        if (f0 * f1 > 0)
        {
            cout << "No solution" << endl;
            continue;
        }
        // f is non-increasing on [0, 1] given the constraints -> bisection works
        double lo = 0, hi = 1;
        for (int it = 0; it < 100; it++)
        {
            double mid = (lo + hi) / 2.0;
            if (f(lo) * f(mid) <= 0) hi = mid;
            else                     lo = mid;
        }
        printf("%.4f\n", (lo + hi) / 2.0);
    }
    return 0;
}
