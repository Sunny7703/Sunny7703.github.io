# UVa 100 - The 3n + 1 problem

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 100
- **Problem Title:** The 3n + 1 problem
- **Problem Link:** https://onlinejudge.org/external/1/100.pdf
- **Source Code (Original code):** [src/100-original.cpp](./src/100-original.cpp)
- **Source Code (Improved code):** [src/100-improved.cpp](./src/100-improved.cpp)

## 2. Problem Statement in My Own Words

According to the algorithm, while n != 1, the cycle count will be added once by running one step.
From the range i to j, I need to output the maximum cycle count.

- What is the input?
  A: i and j

- What is the expected output?
  A: i, j, and the maximum cycle count across all numbers in the range

- rules:
  - if n is odd: `n = 3n + 1`
  - if n is even: `n = n / 2`
  - count steps until n == 1 (including the initial n)
  - i and j can come in any order (j might be < i) -> must handle that
  - output must print the ORIGINAL i and j (before swapping)

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- write a separate function to calculate the cycle count for a single number
- loop from i to j, call the function for each, track the max

### Final Strategy

- `algorithm(n)`: count steps until n == 1
- main: read i, j; swap a copy if needed (keep originals for output); loop a..b and track max
- two improvements found after the first version:
  1. avoid calling `algorithm()` twice per number -> save the result in a variable
  2. use `long long` for n inside the function -> intermediate values of `3n+1` can overflow `int`
- edge cases:
  - i > j (input can be reversed) -> swap before looping, but print original order
  - n = 1 -> cycle length is 1 (loop doesn't run)

## 4. Pseudocode

```text
START
1. algorithm(n):
2. count = 1
3. while n != 1:
4. if n is odd: n = 3n + 1
5. if n is even: n = n / 2
6. count++
7. return count

8. main:
9. while read i, j:
10. print i, j
11. a = min(i,j), b = max(i,j)
12. mx = 0
13. for k = a..b: mx = max(mx, algorithm(k))
14. print mx
END
```

## 5. Original Code vs Improved Code

### Original Code

```cpp
#include <iostream>
using namespace std;

int algorithm(int n)
{
    int count = 1;
    while(n != 1)
    {
        if(n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        count++;
    }

    return count;
}

int main()
{
    int i = 0, j = 0;

    while(cin >> i >> j)
    {
        cout << i << " " << j << " ";

        if(j < i)
            swap(i,j);

        int max = 0;
        for(int k = i; k <= j; k++)
        {
            if(algorithm(k) > max)
                max = algorithm(k);
        }

        cout << max << endl;
    }
    return 0;
}
```

**How it can be improved:**

- calling `algorithm()` TWICE per number: once to compare, once to get the value
  - wastes time -> the sequence can be long, so computing it twice is unnecessary
  - fix: save the result in a variable, compare that
  ```cpp
  int len = algorithm(k);
  if(len > max) max = len;
  ```
- the parameter is `int n`, but `3 * n + 1` can overflow `int` for large n
  - `int` max is ~2.1 billion; `3n+1` can go well above that during the sequence
  - fix: use `long long` for the parameter
  ```cpp
  int algorithm(long long n)
  ```
- `swap(i, j)` modifies `i` and `j` directly -> this is fine because the originals are already printed
  - but using separate variables `a` and `b` makes it clearer

### Improved Code

```cpp
#include <iostream>
using namespace std;

int algorithm(long long n)
{
    int count = 1;
    while(n != 1)
    {
        if(n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        count++;
    }

    return count;
}

int main()
{
    int i = 0, j = 0;

    while(cin >> i >> j)
    {
        cout << i << " " << j << " ";

        int a = i, b = j;
        if(a > b) swap(a, b);

        int mx = 0;
        for(int k = a; k <= b; k++)
        {
            int len = algorithm(k);
            if(len > mx) mx = len;
        }

        cout << mx << endl;
    }
    return 0;
}
```

**What changed:**

- `algorithm(long long n)` -> safe from overflow on `3n+1`
- `int len = algorithm(k)` -> called only once, compared and stored
- `a` and `b` are copies -> `i` and `j` stay unchanged (cleaner intent)

## 6. Difference and Reflection

### Key Differences

| Item | Original Code | Improved Code |
|---|---|---|
| Logic | calls `algorithm()` twice per k | calls once, saves result |
| Edge Cases | `int n` can overflow on 3n+1 | `long long n` prevents overflow |
| Output Handling | same (both correct) | same |
| Other | swaps i,j directly (works but less clear) | uses a,b copies (clearer) |

### Reflection

- my mistake: didn't notice I was calling the function twice -> doubles the computation time
- what I learned:
  - if I call a function just to compare its result, SAVE it -> don't call again to use it
  - `3n+1` grows fast -> even if input is `int`, intermediate values can overflow -> use `long long` inside
  - naming matters: `max` shadows `std::max`; `mx` avoids the conflict

* next time: whenever I write `if(f(x) > best) best = f(x);`, refactor to `int val = f(x); if(val > best) best = val;` immediately
