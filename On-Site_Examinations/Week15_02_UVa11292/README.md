# UVa 11292 - Dragon of Loowater

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11292
- **Problem Title:** Dragon of Loowater
- **Problem Link:** https://onlinejudge.org/external/112/11292.pdf
- **Source Code (Fail):** [src/11292-fail.cpp](./src/11292-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11292-correct.cpp](./src/11292-correct.cpp)

## 2. Problem Statement in My Own Words

- a dragon has `n` heads, each with a diameter
- `m` knights available, each has a height = max head diameter they can chop
- a knight can chop a head if their height >= head diameter
- each knight costs gold = their height; each knight used once
- Input: many cases of `n m`, then `n` head diameters, then `m` knight heights; `0 0` ends
- Output: minimum total gold, or `Loowater is doomed!` if not all heads can be chopped
- **Goal: assign knights to heads to minimize total cost**
  - greedy: sort both ascending, match each head with the CHEAPEST knight that works

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first (wrong) idea: sort descending and pick the first knight that fits -> assigns the BIGGEST knight, not the cheapest
- correct idea: sort ASCENDING and for each head (smallest first), find the cheapest knight that can handle it

### Final Strategy

- sort both dragons and knights ascending
- two pointers: `i` for dragons, `j` for knights
- for each dragon `i`:
  - skip knights that are too small (`knight[j] < dragon[i]` -> `j++`)
  - if no knight left -> "doomed"
  - else assign `knight[j]` to `dragon[i]`, add `knight[j]` to cost, advance both
- why it works:
  - sorting ascending + greedy ensures each dragon gets the cheapest possible knight
  - if a small knight can't handle the current (smallest remaining) dragon, it can't handle any larger dragon either -> safe to skip it
  - two-pointer scan is O(n + m) after sorting
- edge cases:
  - more dragons than knights -> doomed
  - all knights too small -> doomed
  - exact matches

## 4. Pseudocode

```text
START
1. while read n, m and not both 0:
2. read n dragons, m knights
3. sort both ascending
4. cost = 0, j = 0, ok = true
5. for i = 0..n-1:
6. while j < m and knight[j] < dragon[i]: j++
7. if j >= m: ok = false; break
8. cost += knight[j]; j++
9. if ok: print cost; else: print "Loowater is doomed!"
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && n >= 1 && n <= 2000 && m >= 1 && m <= 2000)
    {
        if (n == 0 && m == 0) break;

        int dragon[2000], knight[2000];
        int max = 0, min = 2000;

        for (int i = 0; i < n; i++) cin >> dragon[i];
        for (int j = 0; j < m; j++) cin >> knight[j];

        // sort descending (wrong direction for min-cost)
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                if (dragon[i] > dragon[k])
                    swap(dragon[i], dragon[k]);

        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++)
                if (knight[j] > knight[k])
                    swap(knight[j], knight[k]);

        int o = 0;
        bool r = false;
        for (int i = 0; i < n; i++)
        {
            r = false;
            for (int j = 0; j < m; j++)
            {
                if (knight[j] >= dragon[i])
                {
                    o += knight[j];
                    knight[j] = 0;
                    r = true;
                    break;
                }
            }
        }

        if (m < n || o == 0 || !r)
            cout << "Loowater is doomed!" << endl;
        else
            cout << o << endl;
    }
}
```

**Why it failed:**

- sorts DESCENDING -> the greedy picks the BIGGEST knight for each dragon, not the cheapest
  - example: dragons [4, 5], knights [4, 7, 8]
  - sorted desc: dragons [5, 4], knights [8, 7, 4]
  - dragon 5 -> knight 8 (cost 8); dragon 4 -> knight 7 (cost 7); total = 15
  - correct: sort asc -> dragon 4 -> knight 4 (cost 4); dragon 5 -> knight 7 (cost 7); total = 11
- the "sort" itself is a non-standard loop that happens to produce descending order but is O(n^2) and hard to read; should just use `sort()`
- `while` condition `n >= 1` makes the `if (n == 0 && m == 0) break;` unreachable
- `int max = 0, min = 2000;` shadows `std::max`/`std::min` and is never used
- marking used knights as `knight[j] = 0` is fragile; two-pointer is cleaner

### Correct Code

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while (cin >> n >> m && (n || m))
    {
        int dragon[2000], knight[2000];

        for (int i = 0; i < n; i++) cin >> dragon[i];
        for (int j = 0; j < m; j++) cin >> knight[j];

        sort(dragon, dragon + n); // ascending
        sort(knight, knight + m); // ascending

        int cost = 0, j = 0;
        bool ok = true;

        for (int i = 0; i < n; i++)
        {
            // find the cheapest knight that can handle this dragon
            while (j < m && knight[j] < dragon[i]) j++;
            if (j >= m) { ok = false; break; }
            cost += knight[j];
            j++; // this knight is used up
        }

        if (ok)
            cout << cost << endl;
        else
            cout << "Loowater is doomed!" << endl;
    }
    return 0;
}
```

**Why it works:**

- sorts ASCENDING -> smallest heads first, cheapest knights first
- two-pointer greedy: each dragon gets the cheapest knight that can handle it
- skipping too-small knights is safe (they can't handle any remaining dragon either)
- `while (cin >> n >> m && (n || m))` correctly stops at `0 0`
- `sort()` is clean and O(n log n)
- two-pointer is O(n + m) -> total O((n+m) log(n+m))

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | sort descending -> picks biggest knight | sort ascending -> picks cheapest knight |
| Edge Cases | unreachable `0 0` check; unused variables | clean termination |
| Output Handling | wrong total (too expensive) | minimum total |
| Other | O(n^2) hand-rolled sort, `knight[j]=0` hack | `sort()` + two-pointer |

### Reflection

- my mistake: sorted the wrong direction -> the greedy grabbed the most expensive knight instead of the cheapest
- what I learned:
  - "minimize total cost" + "assign smallest resource that fits" -> sort ASCENDING + greedy
  - two-pointer is cleaner than marking used slots as 0
  - use `sort()` instead of hand-rolling a non-standard sort loop
  - the sample happened to partially work because there was only one valid assignment, hiding the bug

* next time: when the problem says "minimum cost", sort ASCENDING and assign the cheapest that works; test with a case where multiple knights can handle the same dragon to expose wrong-direction bugs
