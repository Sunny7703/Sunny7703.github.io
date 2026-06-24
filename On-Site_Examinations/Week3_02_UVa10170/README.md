# UVa 10170 - The Hotel with Infinite Rooms

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10170
- **Problem Title:** The Hotel with Infinite Rooms
- **Problem Link:** https://onlinejudge.org/external/101/10170.pdf
- **Source Code (Fail):** [src/10170-fail.cpp](./src/10170-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10170-correct.cpp](./src/10170-correct.cpp)

## 2. Problem Statement in My Own Words

- groups come one by one: `S`, `S+1`, `S+2` ... (each 1 person bigger)
- a group of `n` people fills `n` days in a row, no gaps
- Input: many `S D` lines until end (`S` = first group, `D` = a day)
- Output: group size on day `D`
- **Goal: find which group covers day `D`**
  - days `1..S` = group `S`, next `S+1` days = group `S+1`, ...
  - = first group where total days reach `D`

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: go group by group, add up the days
- problem: `D` can be big -> can't count day by day -> count group by group
- need `long long` for `D`

### Final Strategy

- add up days, one group at a time
- start `g = S`, add `g` days, then go to `g+1`
- stop when `sum >= D` -> that group is the answer
- why it works: no empty day between groups, so the first group that reaches `D` holds day `D`
- edge cases:
  - `sum == D` (day `D` on the edge) -> still that group
  - `S >= D` (day `D` is in the first group)
  - many test cases -> need a read loop
  - big `D` -> use `long long`

## 4. Pseudocode

```text
START
1. while read (s, d) until end:
2.     sum = 0
3.     while sum < d:
4.         sum += s      // this group uses s days
5.         s++           // next group is 1 bigger
6.     print s - 1       // took 1 extra step, so minus 1
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    long long s;
    long long d;

    cin >> s >> d;


    long long sum = 0;
    while(sum < d)
    {
        sum += s;
        if(sum < d)
            s++;
    }

        cout << s << endl;
    }
    return 0;
}
```

**Why it failed:**

- one extra `}` after `cout` -> `main()` ends too early -> `return 0;` falls outside -> does not compile (CE)
- only one read, no loop -> reads 1 case only -> misses the rest
- the math part was actually fine

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int s;
    long long d;
    while(cin >> s >> d)
    {
        long long sum = 0;
        while(sum < d)
        {
            sum += s;
            s++;
        }

        cout << s - 1 << endl;
    }
    return 0;
}
```

**Why it works:**

- `while(cin >> s >> d)` -> reads all cases until the end
- inner loop adds group days until `sum >= d`
- print `s - 1` because `s` went up 1 extra time
- `d` is `long long` -> safe for big numbers

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | `s++` only when `sum < d`, print `s` | always `s++`, print `s - 1` (same answer, cleaner) |
| Edge Cases | no loop -> 1 case only | `while(cin >> ...)` -> all cases |
| Output Handling | print `s` | print `s - 1` (both give the right number) |
| Other | extra `}` -> does not compile | braces match -> compiles, AC |

### Reflection

- my mistake: extra `}`, and forgot the read loop
- what I learned: CE is not a logic bug -> read the error line first, and count `{` and `}`

* next time: add `while(cin >> ...)` from the start, and compile on my PC before submit
