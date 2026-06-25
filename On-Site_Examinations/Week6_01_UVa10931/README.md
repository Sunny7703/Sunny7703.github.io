# UVa 10931 - Parity

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10931
- **Problem Title:** Parity
- **Problem Link:** https://onlinejudge.org/external/109/10931.pdf
- **Source Code (Fail):** [src/10931-fail.cpp](./src/10931-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10931-correct.cpp](./src/10931-correct.cpp)

## 2. Problem Statement in My Own Words

- read positive integers `N`, one per line, until `N = 0` (don't print 0)
- show `N` in binary, and count how many `1`s it has
- Output format: `The parity of <binary> is <ones> (mod 2).`
- **Goal: convert N to binary and count the 1s**
  - binary has no leading zero
  - parity = number of 1 bits

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: try each power of 2 from high to low; if `N >= 2^i`, that bit is 1, subtract it
- problem: where to start? fixed at i=30 -> tons of leading zeros for small N
- safer idea: divide N by 2 over and over, the remainder is the next bit

### Final Strategy

- loop while `tmp > 0`:
  - `bit = tmp % 2` -> last bit
  - if `bit == 1` -> `ones++`
  - prepend `bit` to `bin` (so the highest bit is on the left)
  - `tmp /= 2`
- use a copy `tmp = n` so the original `n` is not destroyed (in case I print it later)
- why it works: `%2` peels the lowest bit, `/2` drops it; loop stops on its own when no bits are left -> no leading zeros
- edge cases:
  - `N = 1` -> `bin = "1"`, parity 1
  - input `0` -> stop, no output
  - output ends with `).` (no extra space after)

## 4. Pseudocode

```text
START
1. while read n and n != 0:
2. bin = "", ones = 0, tmp = n
3. while tmp > 0:
4. bit = tmp % 2
5. if bit == 1: ones += 1
6. bin = (char)('0' + bit) + bin // prepend
7. tmp /= 2
8. print "The parity of <bin> is <ones> (mod 2)."
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int I;
    while(cin >> I && I != 0)
    {
        int one = 0;
        cout << "The parity of ";
        for(int i = 30; i >= 0; i--)
        {
            if(I >= pow(2, i))
            {
                cout << "1";
                I -= pow(2, i);
                one++;
            }
            else if(I < pow(2, i) && i != 0)
                cout << "0";
        }

        cout << " is " << one << " (mod 2). " << endl;
    }
    return 0;
}
```

**Why it failed:**

- starts from `i = 30` and prints every bit -> tons of leading zeros (e.g. `N = 1` -> `0000...0001`)
- `else if (... && i != 0)` skips the `i = 0` case when the bit is 0 -> the last `0` is missing
  - e.g. `N = 2` should be `10`, prints only `1`; `N = 10` should be `1010`, prints `101`
- output ends with `" (mod 2). "` (extra space before `endl`) -> trailing space -> wrong format
- `pow(2, i)` returns `double` -> comparing `int` with `double` is risky for big numbers (slow too)
- `pow` is from `<cmath>` -> would also need to include it; this version did not -> won't compile on a strict setup

### Correct Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        string bin = "";
        int ones = 0;
        int tmp = n;
        while (tmp > 0)
        {
            int bit = tmp % 2;
            if (bit == 1) ones++;
            bin = (char)('0' + bit) + bin;
            tmp /= 2;
        }
        cout << "The parity of " << bin
             << " is " << ones
             << " (mod 2)." << endl;
    }
    return 0;
}
```

**Why it works:**

- `%2` and `/2` do real binary conversion, no `pow`, no `double`
- loop ends on its own when `tmp` hits 0 -> NO leading zeros, NO missing last bit
- prepending each bit puts the highest bit on the left -> correct order
- uses `tmp` so the original `n` stays untouched
- output is exactly `... (mod 2).` -> no trailing space, matches the required format

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | walk powers of 2 from i=30 down with `pow` | `%2` and `/2` until tmp is 0 |
| Edge Cases | leading zeros; loses last `0` (i=0 skipped) | no leading zeros; every bit kept |
| Output Handling | extra space before `endl` -> wrong format | clean `).` ending |
| Other | uses `pow` (double) without including `<cmath>` | pure int math, no extra header |

### Reflection

- my mistake: fixed the loop at `i = 30` (so always 31 chars, lots of leading zeros), AND wrote `i != 0` which dropped the last zero bit
- what I learned:
  - don't pre-decide how many bits to print -> let the loop end naturally
  - `pow` returns `double` -> avoid mixing it with `int` comparisons; use `%2` / `/2` (or `>>1` and `&1`)
  - check the output string char by char -> a stray space costs a WA

* next time: build the answer from low bit to high bit and prepend; print exactly what the spec shows, nothing more
