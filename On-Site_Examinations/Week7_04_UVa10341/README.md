# UVa 10341 - Solve It

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10341
- **Problem Title:** Solve It
- **Problem Link:** https://onlinejudge.org/external/103/10341.pdf
- **Source Code (Fail):** [src/10341-fail.cpp](./src/10341-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10341-correct.cpp](./src/10341-correct.cpp)

## 2. Problem Statement in My Own Words

- given 6 integers `p, q, r, s, t, u`, define
  - `f(x) = p*e^(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x^2 + u`
- find `x` in `[0, 1]` such that `f(x) = 0`
- constraints: `0 <= p, r <= 20`, `-20 <= q, s, t <= 0`
- Output: the root with 4 decimals, OR `No solution` if there is none in `[0, 1]`
- **Goal: find the root of f in [0, 1] (or say no solution)**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: try x = 0, 0.01, 0.02, ... until f changes sign -> too slow, not precise
- key observation: given the constraints, every term of f is non-increasing on `[0, 1]`:
  - `p * e^(-x)`: `p >= 0` and `e^(-x)` is decreasing -> non-increasing
  - `q * sin(x)`: `q <= 0` and `sin(x)` is increasing on `[0,1]` -> non-increasing
  - `r * cos(x)`: `r >= 0` and `cos(x)` is decreasing -> non-increasing
  - `s * tan(x)`: `s <= 0` and `tan(x)` is increasing -> non-increasing
  - `t * x^2`: `t <= 0` and `x^2` is increasing -> non-increasing
  - `u`: constant
- so `f` is non-increasing on `[0, 1]` -> at most one root, easy to find with bisection

### Final Strategy

- check `f(0) * f(1)`:
  - if > 0 -> they have the same sign -> no root in `[0, 1]` -> `No solution`
  - else -> there IS a root somewhere in `[0, 1]`
- bisection in `[lo, hi] = [0, 1]`:
  - repeatedly take `mid`, check `f(lo) * f(mid)`:
    - `<= 0` -> root in `[lo, mid]` -> `hi = mid`
    - else -> root in `[mid, hi]` -> `lo = mid`
- after enough iterations, print `(lo + hi) / 2` with 4 decimals
- why it works:
  - intermediate value theorem -> sign change means a root exists in between
  - bisection halves the interval each step -> converges fast
  - ~100 iterations is way more than enough for 4-decimal precision (`1 / 2^100` is tiny)
- edge cases:
  - `f(0) == 0` -> root is 0
  - `f(1) == 0` -> root is 1
  - `f(0) * f(1) > 0` -> no root -> print `No solution`
  - `tan(1)` is finite (1 rad < pi/2) -> no domain issues

## 4. Pseudocode

```text
START
1. while read p, q, r, s, t, u:
2. if f(0) * f(1) > 0: print "No solution"; continue
3. lo = 0, hi = 1
4. repeat ~100 times:
5. mid = (lo + hi) / 2
6. if f(lo) * f(mid) <= 0: hi = mid
7. else: lo = mid
8. print (lo + hi) / 2 with 4 decimals
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
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



    }
    return 0;
}
```

**Why it failed:**

- only set up the input reading and `f`
- never checked for a root, never ran bisection, never printed -> no output

### Correct Code

```cpp
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
```

**Why it works:**

- same-sign check `f(0)*f(1) > 0` catches the no-solution case
- otherwise, bisection narrows the interval each step
- 100 iterations -> interval shrinks by `1 / 2^100`, far below 4-decimal precision
- `printf("%.4f")` -> output format matches the spec

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> no root finding | bisection on `[0, 1]` |
| Edge Cases | none | handles `No solution` via sign check |
| Output Handling | prints nothing | prints either 4-decimal root or `No solution` |
| Other | only setup | uses monotonicity of f |

### Reflection

- my mistake: stopped at setting up `f` and reading input
- what I learned:
  - the sign of `f(lo) * f(hi)` tells me if a root is in between (intermediate value theorem)
  - given the input constraints, f is non-increasing -> at most one root -> bisection is safe
  - "100 iterations" is a clean way to stop without fiddling with epsilon

* next time:
  - other approaches:
    - secant method (uses two points to extrapolate) -> faster, but needs care if the slope is tiny
    - Newton's method (uses derivative) -> fastest, but needs the derivative and a good start
  - always prove monotonicity (or unique root) before trusting bisection on a generic function
