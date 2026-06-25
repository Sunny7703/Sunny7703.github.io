#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double ax, ay, bx, by, cx, cy, dx, dy;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
                 &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy) == 8)
    {
        // edges are A-B and C-D; one of A/B equals one of C/D (the shared corner)
        // call the shared point S; the other two are P1 and P2
        // fourth point = P1 + P2 - S
        double sx, sy, p1x, p1y, p2x, p2y;

        if      (ax == cx && ay == cy) { sx = ax; sy = ay; p1x = bx; p1y = by; p2x = dx; p2y = dy; }
        else if (ax == dx && ay == dy) { sx = ax; sy = ay; p1x = bx; p1y = by; p2x = cx; p2y = cy; }
        else if (bx == cx && by == cy) { sx = bx; sy = by; p1x = ax; p1y = ay; p2x = dx; p2y = dy; }
        else                            { sx = bx; sy = by; p1x = ax; p1y = ay; p2x = cx; p2y = cy; }

        double fx = p1x + p2x - sx;
        double fy = p1y + p2y - sy;
        printf("%.3f %.3f\n", fx, fy);
    }
    return 0;
}
