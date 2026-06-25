# UVa 11136 - Hoax or what

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11136
- **Problem Title:** Hoax or what
- **Problem Link:** https://onlinejudge.org/external/111/11136.pdf
- **Source Code (Fail):** [src/11136-fail.cpp](./src/11136-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11136-correct.cpp](./src/11136-correct.cpp)

## 2. Problem Statement in My Own Words

- a supermarket promo:
  - every day, customers drop bills into an urn (one bill per person, value can repeat)
  - at the end of each day, the supermarket picks the BIGGEST bill and the SMALLEST bill out of the urn (the rest stays!)
  - the cost to the supermarket that day = `max - min`
- Input: `N`, then for `N` days: `k` + `k` bill values
- Output: total cost over all days; `N == 0` ends input
- **Goal: simulate each day, sum up (max - min) across all days**
  - bills already in the urn from previous days STAY -> need a data structure that supports insert + min + max + erase

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: sort the list each day -> too slow if there are many days
- better: a `multiset<long long>` keeps values sorted; `*begin()` is min, `*prev(end())` is max

### Final Strategy

- read `N`; if 0, stop
- `multiset<long long> s` and `long long sum = 0`
- for each day:
  - read `k` bills, insert all of them
  - take the smallest and the largest -> `sum += max - min`
  - erase BOTH from the set
- print `sum`
- why it works:
  - `multiset` keeps the set sorted in `O(log n)` per insert/erase
  - min and max are at the two ends -> `O(log n)` to access and erase
- edge cases:
  - bills can be up to ~`10^9`, days many -> total can overflow 32-bit -> use `long long`
  - duplicates allowed -> use `multiset`, not `set`
  - bills remain across days -> do NOT clear between days

## 4. Pseudocode

```text
START
1. while read n and n != 0:
2. s = empty multiset, sum = 0
3. repeat n times:
4. read k bills, insert all into s
5. min = *s.begin(), max = *prev(s.end())
6. sum += max - min
7. erase max, erase min from s
8. print sum
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        multiset<long long> s;
        long long sum = 0;

        for (int day = 0; day < n; day++)
        {
            int k;
            scanf("%d", &k);



        }
    }
    return 0;
}
```

**Why it failed:**

- only set up `s`, `sum`, the day loop, and `k`
- never inserted bills, never picked max/min, never printed -> no output

### Correct Code

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) == 1 && n != 0)
    {
        multiset<long long> s;
        long long sum = 0;

        for (int day = 0; day < n; day++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 0; j < k; j++)
            {
                long long x;
                scanf("%lld", &x);
                s.insert(x);
            }

            auto it_lo = s.begin();
            auto it_hi = prev(s.end());
            sum += *it_hi - *it_lo;

            s.erase(it_hi);
            s.erase(s.begin());
        }
        printf("%lld\n", sum);
    }
    return 0;
}
```

**Why it works:**

- `multiset` keeps everything sorted -> `*begin()` is min, `*prev(end())` is max
- add the new bills first, THEN do `max - min` (so today's bills are part of the day's pool)
- erase the max bill, then erase the min bill -> the rest stays for tomorrow
- `long long` -> no overflow

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> no simulation | insert bills, take max - min, erase both |
| Edge Cases | none handled | duplicates ok (multiset), `long long` for big sums |
| Output Handling | prints nothing | prints total after all days |
| Other | only setup | bills stay across days (no clear) |

### Reflection

- my mistake: stopped at the setup, didn't simulate any day
- what I learned:
  - `multiset` is perfect when I need a sorted bag with duplicates + fast min / max / erase
  - bills carry over -> do NOT reset between days
  - check value ranges first -> 10^9 sums forced `long long`

* next time: pick the data structure to match the operations I need; for "insert + min + max + erase", `multiset` (or two heaps) is the right tool
