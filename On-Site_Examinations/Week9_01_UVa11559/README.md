# UVa 11559 - Event Planning

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11559
- **Problem Title:** Event Planning
- **Problem Link:** https://onlinejudge.org/external/115/11559.pdf
- **Source Code (Fail):** [src/11559-fail.cpp](src./11559-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11559-correct.cpp](src./11559-correct.cpp)

## 2. Problem Statement in My Own Words

- planning a group trip:
  - `N` people, budget `B`, `H` hotels, `W` weekends to choose from
  - each hotel has a per-person price, and a bed count for each weekend
  - everyone must stay at the SAME hotel
- Input: many cases until EOF; each = `N B H W`, then for each hotel: price, then `W` bed counts
- Output: MINIMUM total cost where beds >= N AND total <= B; or `stay home` if nothing works
- **Goal: find the cheapest valid (hotel, weekend) combo**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: for every (hotel, weekend), check if beds >= N and cost <= B
- tricky part: must keep track of the MINIMUM cost, not just any valid cost
- forgot this at first -> just overwrote `out` with the latest valid cost

### Final Strategy

- for each hotel `j`:
  - read price `p[j]`, then for each weekend `i` read beds `a[j][i]`
  - if `a[j][i] >= n` (enough beds):
    - compute `cost = p[j] * n`
    - if `cost <= b` AND (`out == 0` or `cost < out`): update `out = cost`
- after all hotels: if `out != 0` print it, else `stay home`
- why it works:
  - checks every (hotel, weekend) combo -> won't miss any option
  - the `cost < out` condition keeps only the cheapest one
  - `out == 0` means "haven't found any valid option yet"
- edge cases:
  - no hotel has enough beds -> out stays 0 -> "stay home"
  - all valid options are over budget -> out stays 0 -> "stay home"
  - cheap hotel comes BEFORE expensive one -> must NOT let the expensive one overwrite

## 4. Pseudocode

```text
START
1. while read n, b, h, w:
2. out = 0
3. for each hotel j:
4. read price p[j]
5. for each weekend i:
6. read beds a[j][i]
7. if a[j][i] >= n:
8. cost = p[j] * n
9. if cost <= b AND (out == 0 OR cost < out): out = cost
10. if out != 0: print out; else: print "stay home"
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n, b, h, w;
    int p[20], a[20][15];

    while(cin >> n >> b >> h >> w)
    {
        int out = 0;

        for(int j = 0; j < h; j++)
        {
            cin >> p[j];

            for(int i = 0; i < w; i++)
            {
                cin >> a[j][i];
                if(a[j][i] >= n)
                {
                    if(p[j] * n <= b)
                        out = p[j] * n; // BUG: overwrites, does NOT keep minimum
                }
            }
        }

        if(out != 0)
            cout << out << endl;
        else
            cout << "stay home" << endl;
    }
}
```

**Why it failed:**

- `out = p[j] * n` just overwrites with the LATEST valid cost, not the smallest
- if a cheaper hotel comes first and a more expensive one comes later, the expensive one stomps the cheap one
- example: hotels with cost 100 and 500 (both have enough beds, both within budget)
  - after hotel 1: `out = 100` (good)
  - after hotel 2: `out = 500` (wrong, should stay at 100)
  - prints 500 instead of 100
- the sample test cases happen to pass by accident (the cheapest valid option is also the last one found)

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n, b, h, w;
    int p[20], a[20][15];

    while(cin >> n >> b >> h >> w)
    {
        int out = 0;

        for(int j = 0; j < h; j++)
        {
            cin >> p[j];

            for(int i = 0; i < w; i++)
            {
                cin >> a[j][i];
                if(a[j][i] >= n)
                {
                    int cost = p[j] * n;
                    if(cost <= b && (out == 0 || cost < out))
                        out = cost; // keeps the minimum
                }
            }
        }

        if(out != 0)
            cout << out << endl;
        else
            cout << "stay home" << endl;
    }
}
```

**Why it works:**

- `out == 0 || cost < out` -> only updates when this cost is CHEAPER than the current best (or first valid find)
- scans every (hotel, weekend) -> won't miss the cheapest option
- `out == 0` at the end means no valid option was found -> "stay home"

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | `out = cost` (overwrites blindly) | `if (out == 0 or cost < out) out = cost` (keeps min) |
| Edge Cases | fails when cheap hotel appears before expensive one | correct for any order |
| Output Handling | same format | same format |
| Other | sample passes by accident (cheapest is last) | works on all inputs |

### Reflection

- my mistake: wrote `out = cost` without checking if the new cost is actually cheaper -> a classic "forgot to track the minimum" bug
- what I learned:
  - when the problem says "minimum", always compare with the current best before overwriting
  - sample tests can pass by coincidence (the cheapest happened to be last) -> need to test with reversed order too
  - fix is just one extra condition: `out == 0 || cost < out`

* next time: whenever I write an assignment inside a loop, ask "should this be `=` or `min(out, cost)`?" -> the word "minimum" in the problem is the trigger
