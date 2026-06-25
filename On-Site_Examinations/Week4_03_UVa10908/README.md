# UVa 10908 - Largest Square

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10908
- **Problem Title:** Largest Square
- **Problem Link:** https://onlinejudge.org/external/109/10908.pdf
- **Source Code (Fail):** [src/10908-fail.cpp](./src/10908-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10908-correct.cpp](./src/10908-correct.cpp)

## 2. Problem Statement in My Own Words

- given an `M x N` grid of letters
- for each query `(r, c)`, find the BIGGEST square that:
  - is centered exactly at cell `(r, c)`
  - contains only the SAME letter (the one at `(r, c)`)
- the center is a grid cell -> the side length is always ODD: `2k + 1`
- Input: `T` test cases; each = `M N Q`, then `M` rows, then `Q` queries `(r, c)`
- Output: the side length for each query
- **Goal: for each center, find the biggest k such that the (2k+1) x (2k+1) block is all the same letter**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: try k = 1, 2, 3, ... and check the whole block each time -> too slow
- better: grow OUTWARD by one ring at a time; only check the new ring, not the whole block

### Final Strategy

- start with `k = 0` (the center alone, side = 1)
- repeat:
  - try `nk = k + 1`
  - if the new ring is out of bounds -> stop
  - check the 4 sides of the new ring (top row, bottom row, left col, right col)
  - if any cell != center letter -> stop
  - else `k = nk` and try again
- answer = `2 * k + 1`
- why it works: the inside is already known to be all the same letter (from the previous step), so only the new ring matters -> each step is `O(k)`
- edge cases:
  - center near a border -> stop as soon as the ring goes out of bounds
  - center letter is unique -> answer = 1 (no expansion)

## 4. Pseudocode

```text
START
1. read T
2. repeat T times:
3. read M, N, Q and the grid
4. for each query (r, c):
5. ch = grid[r][c], k = 0
6. while true:
7. nk = k + 1
8. if (r-nk, c-nk) or (r+nk, c+nk) out of bounds: break
9. if any cell on the new ring != ch: break
10. k = nk
11. print 2*k + 1
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, Q;
        cin >> M >> N >> Q;

        string g[105];
        for (int i = 0; i < M; i++)
            cin >> g[i];

        while (Q--)
        {
            int r, c;
            cin >> r >> c;



        }
    }
    return 0;
}
```

**Why it failed:**

- only set up the read loop and got `(r, c)`
- never expanded, never checked, never printed -> no output

### Correct Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int M, N, Q;
        cin >> M >> N >> Q;

        string g[105];
        for (int i = 0; i < M; i++)
            cin >> g[i];

        while (Q--)
        {
            int r, c;
            cin >> r >> c;

            char ch = g[r][c];
            int k = 0;

            // grow the square outward; check the new ring is in bounds and all == ch
            while (true)
            {
                int nk = k + 1;
                if (r - nk < 0 || r + nk >= M || c - nk < 0 || c + nk >= N) break;

                bool ok = true;
                for (int i = r - nk; i <= r + nk && ok; i++)
                    if (g[i][c - nk] != ch || g[i][c + nk] != ch) ok = false;
                for (int j = c - nk; j <= c + nk && ok; j++)
                    if (g[r - nk][j] != ch || g[r + nk][j] != ch) ok = false;

                if (!ok) break;
                k = nk;
            }
            cout << 2 * k + 1 << endl;
        }
    }
    return 0;
}
```

**Why it works:**

- grows outward one ring at a time -> doesn't re-check the inside
- stops as soon as the ring goes out of bounds OR contains a different letter
- final side length is `2*k + 1` (odd, as the problem guarantees)

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> no expansion | grow one ring at a time |
| Edge Cases | none handled | stops at bounds, stops on mismatch |
| Output Handling | prints nothing | prints `2*k + 1` per query |
| Other | only setup | ring-only check, no re-checking |

### Reflection

- my mistake: stopped at the setup, no expansion or output
- what I learned:
  - check only the NEW ring each step -> avoid recomputing the inside
  - the side length is `2k + 1` (odd) because the center is a single cell

* next time: check bounds BEFORE accessing cells; think in terms of "rings" or "layers" instead of full blocks
