# UVa 12149 - Feynman

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 12149
- **Problem Title:** Feynman
- **Problem Link:** https://onlinejudge.org/external/121/12149.pdf
- **Source Code (Fail):** [src/12149-fail.cpp](./src/12149-fail.cpp)
- **Source Code (Correct/Accepted):** [src/12149-correct.cpp](./src/12149-correct.cpp)

## 2. Problem Statement in My Own Words

- read `n`, one per line, until `n == 0` (don't print 0)
- count ALL squares (any size) inside an `n x n` board
- Output: one line per case = the count
- **Goal: total squares = 1*1 + 2*2 + ... + n*n**
  - there are `(n-k+1)^2` squares of size `k x k`, summed over `k = 1..n` -> equals sum of `i*i` for `i = 1..n`

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: count squares by size
  - size 1: `n*n`
  - size 2: `(n-1)*(n-1)`
  - ...
  - size n: `1*1`
- so the answer is just `sum of i*i for i = 1..n`

### Final Strategy

- loop `i` from `n` down to `1`, add `i*i` to `square`
- print `square`
- why it works: each square of side `k` has `(n-k+1)` choices in each direction -> `(n-k+1)^2` positions; summing over `k` rearranges to `1^2 + 2^2 + ... + n^2`
- edge cases:
  - `n = 1` -> just 1
  - `n = 0` -> stop, no output
  - big `n` (e.g. 100) -> answer = 338350, fits in `int`; for very large n use `long long`

## 4. Pseudocode

```text
START
1. while read n and n != 0:
2. square = 0
3. for i = n down to 1:
4. square += i * i
5. print square
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        int square = 0;



    }
    return 0;
}
```

**Why it failed:**

- only set up the read loop and `square = 0`
- never summed, never printed -> no output

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        int square = 0;
        for(int i = n; i > 0; i--)
        {
            square += i * i;
        }

        cout << square << endl;
    }
    return 0;
}
```

**Why it works:**

- adds up `n*n + (n-1)*(n-1) + ... + 1*1` -> same as `1^2 + 2^2 + ... + n^2`
- that's the total number of squares of any size in an `n x n` board
- reset `square` to 0 each case; stop when input is 0

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> no summing | sums `i*i` from `n` down to `1` |
| Edge Cases | none handled | stops at 0, resets sum per case |
| Output Handling | prints nothing | prints the total per case |
| Other | just the variable setup | full loop body |

### Reflection

- my mistake: stopped at the setup, never wrote the summing loop or output
- what I learned:
  - count by SIZE: number of `k x k` squares = `(n-k+1)^2`; summed -> `1^2 + 2^2 + ... + n^2`
  - closed form exists: `n(n+1)(2n+1)/6` -> O(1) instead of O(n); needs `long long` for big n
  - reset accumulators inside the loop so each case starts fresh

* next time: finish the loop body and the output before testing; check if a closed-form formula can replace the loop
