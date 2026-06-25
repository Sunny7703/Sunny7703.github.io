# UVa 10242 - Fourth Point !!

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10242
- **Problem Title:** Fourth Point !!
- **Problem Link:** https://onlinejudge.org/external/102/10242.pdf
- **Source Code (Fail):** [src/10242-fail.cpp](./src/10242-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10242-correct.cpp](./src/10242-correct.cpp)

## 2. Problem Statement in My Own Words

- a parallelogram has 4 corners, but the input gives 8 numbers = 4 (x, y) points
- those 4 points are the endpoints of TWO adjacent sides
- two sides share ONE corner -> that corner appears twice in the input
- so the input really gives 3 distinct corners; find the 4th
- read lines until EOF; print `x y` with 3 decimals
- **Goal: find the missing corner of a parallelogram given 3 of them**
  - shared corner = `S`; the two ends of the sides = `P1`, `P2`
  - fourth point = `P1 + P2 - S`

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: in a parallelogram, opposite sides are equal and parallel -> `P1 - S = D - P2`, so `D = P1 + P2 - S`
- tricky bit: which of the 4 input points is the shared one?

### Final Strategy

- check the 4 ways the points can match:
  - A == C, A == D, B == C, or B == D
- once the shared point `S` is found, the other two are `P1` and `P2`
- output `D = P1 + P2 - S`
- why it works: parallelogram law -> opposite sides are equal vectors; vector from S to P1 plus vector from S to P2 gives vector from S to D
- edge cases:
  - the input doesn't say WHICH points match -> must try all combos
  - input is doubles; compare with `==` is fine here because the same number is written by the same source -> bitwise equal
  - output to the nearest mm -> `%.3f` format

## 4. Pseudocode

```text
START
1. while read 8 numbers: (ax,ay) (bx,by) (cx,cy) (dx,dy):
2. find which of A/B matches C or D -> S (shared), P1, P2 (the rest)
3. fx = p1x + p2x - sx
4. fy = p1y + p2y - sy
5. print fx fy (3 decimals)
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double ax, ay, bx, by, cx, cy, dx, dy;
    while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
                 &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy) == 8)
    {



    }
    return 0;
}
```

**Why it failed:**

- only set up the input reading
- never identified the shared corner, never computed the 4th, never printed -> no output

### Correct Code

```cpp
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
```

**Why it works:**

- 4 if-else cases cover all ways the input can pair up the shared corner
- once `S`, `P1`, `P2` are picked, `D = P1 + P2 - S` is the parallelogram formula
- prints 3 decimals to match "nearest mm"

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> nothing computed | finds shared S, applies `D = P1+P2-S` |
| Edge Cases | none handled | tries all 4 ways the points can match |
| Output Handling | prints nothing | prints `x y` with 3 decimals |
| Other | only setup | uses parallelogram law |

### Reflection

- my mistake: stopped at the input setup
- what I learned:
  - parallelogram law: opposite sides are equal vectors -> `D = P1 + P2 - S`
  - the shared corner isn't labelled -> must try all match cases
  - `%.3f` gives 3 decimals for "to the nearest mm"

* next time: when input order isn't fixed, try every case; pick the geometry formula that fits ("opposite sides are equal")
