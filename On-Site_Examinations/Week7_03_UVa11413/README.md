# UVa 11413 - Fill the Containers

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11413
- **Problem Title:** Fill the Containers
- **Problem Link:** https://onlinejudge.org/external/114/11413.pdf
- **Source Code (Fail):** [src/11413-fail.cpp](./src/11413-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11413-correct.cpp](./src/11413-correct.cpp)

## 2. Problem Statement in My Own Words

- `n` bottles on a conveyor belt, in fixed order; each bottle has a milk amount
- pour them into AT MOST `m` containers, in order; once a container is full, move on to the next
- (so each container takes a CONSECUTIVE block of bottles)
- choose the capacity so that:
  - all bottles fit into `<= m` containers
  - the capacity is as SMALL as possible
- Input: many cases of `n m` + `n` numbers
- Output: the smallest possible capacity
- **Goal: min over caps such that n bottles fit into <= m consecutive groups with each group's sum <= cap**
  - "min-max" feel -> binary search the answer

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: try every capacity from `max(bottle)` up to `sum(bottles)` -> too slow
- key idea: if capacity `X` works, then any `> X` also works -> monotonic -> binary search

### Final Strategy

- binary search the capacity:
  - `lo = max(bottle)` (no single bottle can be bigger than the cap)
  - `hi = sum(bottles)` (everything in 1 container always works)
- check function `ok(cap)`:
  - greedily fill containers left to right
  - if adding the next bottle overflows, start a new container
  - if any single bottle > cap -> impossible
  - if groups used > m -> impossible
- shrink `hi` when `ok`, raise `lo` when not -> answer = smallest `cap` that works
- why it works:
  - "fits in <= m" is monotonic in cap -> binary search
  - greedy from left to right is optimal because the bottles are FIXED in order (consecutive groups)
- edge cases:
  - a single bottle bigger than all others -> lo starts at that value
  - `m = 1` -> the answer is the total sum
  - `m >= n` -> the answer is the max bottle (one bottle each)

## 4. Pseudocode

```text
START
1. while read n, m:
2. read c[0..n-1]
3. lo = max(c), hi = sum(c), ans = hi
4. while lo <= hi:
5. mid = (lo + hi) / 2
6. if ok(mid): ans = mid; hi = mid - 1
7. else: lo = mid + 1
8. print ans

ok(cap):
1. groups = 1, cur = 0
2. for each x in c:
3. if x > cap: return false
4. if cur + x > cap: groups += 1; cur = 0
5. cur += x
6. if groups > m: return false
7. return true
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> c;

int main()
{
    while (cin >> n >> m)
    {
        c.assign(n, 0);
        for (int i = 0; i < n; i++) cin >> c[i];



    }
    return 0;
}
```

**Why it failed:**

- only set up the read loop
- never wrote `ok(cap)`, never binary-searched, never printed -> no output

### Correct Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> c;

// can we cover all bottles with <= m containers, each holding <= cap?
bool ok(int cap)
{
    int groups = 1, cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (c[i] > cap) return false; // a single bottle is already too big
        if (cur + c[i] > cap) { groups++; cur = 0; }
        cur += c[i];
        if (groups > m) return false;
    }
    return true;
}

int main()
{
    while (cin >> n >> m)
    {
        c.assign(n, 0);
        int lo = 0, hi = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> c[i];
            hi += c[i];                 // upper bound = sum of all (1 container)
            if (c[i] > lo) lo = c[i];   // lower bound = max single bottle
        }

        // binary search the smallest cap that works
        int ans = hi;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (ok(mid)) { ans = mid; hi = mid - 1; }
            else         { lo = mid + 1; }
        }
        cout << ans << "\n";
    }
    return 0;
}
```

**Why it works:**

- binary search across the capacity range -> `O(log(sum) * n)`
- `ok(cap)` greedily packs left-to-right -> correct because the order is fixed
- bounds: `max(c) <= ans <= sum(c)` -> safe and tight
- shrinks `hi` whenever a cap works -> ends at the smallest valid cap

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | binary search + greedy check |
| Edge Cases | none | handles `cap < max(c)` and `groups > m` |
| Output Handling | prints nothing | prints the smallest valid cap |
| Other | only setup | "binary search the answer" pattern |

### Reflection

- my mistake: stopped at the setup, no algorithm
- what I learned:
  - "minimize the max" -> usually a binary-search-the-answer problem
  - need a fast `ok(cap)` check; greedy works because the order is fixed
  - good bounds: `lo = max(c)`, `hi = sum(c)`

* next time:
  - whenever the question says "min the max" or "max the min" -> reach for binary search
  - check the WHOLE valid range; pick `lo`/`hi` carefully so the answer is inside
