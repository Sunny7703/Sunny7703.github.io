# UVa 501 - Black Box

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 501
- **Problem Title:** Black Box
- **Problem Link:** https://onlinejudge.org/external/5/501.pdf
- **Source Code (Fail):** [src/501-fail.cpp](./src/501-fail.cpp)
- **Source Code (Correct/Accepted):** [src/501-correct.cpp](./src/501-correct.cpp)

## 2. Problem Statement in My Own Words

- a "Black Box" supports two ops:
  - ADD(x): put x into the box
  - GET: return the i-th smallest, where `i` starts at 1 and goes up by 1 each GET
- Input: `T` test cases, each:
  - `M N`: M is the number of ADDs, N is the number of GETs
  - line of M numbers `a[1..M]` (the ADD values)
  - line of N indexes `u[1..N]` (the GET timings; `u[i]` means: do GET right after the first `u[i]` ADDs are done)
- Output: each GET's answer, one per line; blank line BETWEEN test cases
- **Goal: process a stream of inserts and "give me the i-th smallest" queries efficiently**
  - `i` increases by 1 each GET, so we always want a slightly bigger order stat than before

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: sort every time -> too slow if M is big
- classic trick: TWO heaps split the data at the i-th smallest
  - `lower` (max-heap) holds the i smallest -> top = i-th smallest
  - `upper` (min-heap) holds the rest
- since i goes up by 1 each GET, we just rebalance by 1 each step

### Final Strategy

- two heaps:
  - `lower`: max-heap (top = current i-th smallest)
  - `upper`: min-heap (the rest, in case future GETs need them)
- to insert x:
  - if `lower` is empty OR `x <= lower.top()` -> push to `lower`
  - else -> push to `upper`
- to answer the q-th GET (wantSize = q + 1, since q is 0-indexed):
  - first, ADD all values up to `u[q]`
  - balance: keep moving tops between heaps until `|lower| == wantSize`
  - output `lower.top()`
- why it works:
  - the heap split keeps the i-th smallest at the top of `lower`
  - per-step rebalance is `O(log M)` -> total `O((M+N) log M)`
- edge cases:
  - blank line BETWEEN test cases, not after the last one
  - GETs come AFTER inserts up to `u[q]`, not before -> add first, then query
  - i grows by 1 -> rebalance moves at most 1 element between heaps each step

## 4. Pseudocode

```text
START
1. read T
2. for each test case:
3. read M, N, the M ADD values, the N GET indexes
4. lower = max-heap, upper = min-heap, added = 0
5. for q = 0..N-1:
6. while added < u[q]: insert a[added++] into lower or upper
7. wantSize = q + 1
8. balance |lower| to wantSize by moving tops between heaps
9. print lower.top()
10. print blank line if not the last case
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int M, N;
        scanf("%d %d", &M, &N);

        vector<int> a(M), u(N);
        for (int i = 0; i < M; i++) scanf("%d", &a[i]);
        for (int i = 0; i < N; i++) scanf("%d", &u[i]);



    }
    return 0;
}
```

**Why it failed:**

- only set up the input reading
- never built the two heaps, never processed any GET, never printed -> no output

### Correct Code

```cpp
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int M, N;
        scanf("%d %d", &M, &N);

        vector<int> a(M), u(N);
        for (int i = 0; i < M; i++) scanf("%d", &a[i]);
        for (int i = 0; i < N; i++) scanf("%d", &u[i]);

        // lower = max-heap holding the i smallest seen so far
        // upper = min-heap holding the rest
        priority_queue<int> lower;
        priority_queue<int, vector<int>, greater<int>> upper;

        int added = 0;
        for (int q = 0; q < N; q++)
        {
            // ADD elements up to u[q]
            while (added < u[q])
            {
                int x = a[added++];
                if (!lower.empty() && x > lower.top()) upper.push(x);
                else lower.push(x);
            }

            int wantSize = q + 1; // i-th GET wants i-th smallest
            while ((int)lower.size() < wantSize) { lower.push(upper.top()); upper.pop(); }
            while ((int)lower.size() > wantSize) { upper.push(lower.top()); lower.pop(); }

            printf("%d\n", lower.top());
        }
        if (T) printf("\n"); // blank line BETWEEN test cases (not after the last)
    }
    return 0;
}
```

**Why it works:**

- two heaps keep the data split at the order stat we want
- because i grows by 1 each GET, the rebalance moves at most one element each time
- `lower.top()` is always the current i-th smallest
- `if (T)` after the loop prints the blank line only between cases, not after the last

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> nothing simulated | two heaps + per-step rebalance |
| Edge Cases | none handled | blank line BETWEEN cases, GETs after the right number of ADDs |
| Output Handling | prints nothing | prints i-th smallest per GET |
| Other | only setup | classic order-statistic trick |

### Reflection

- my mistake: stopped at the setup, didn't build the heaps or handle the queries
- what I learned:
  - "i-th smallest" with i growing 1 by 1 -> TWO heaps is the textbook trick
  - balance condition: `|lower| == i` -> top of lower is the answer
  - "blank line between cases" trips me up if I print after each case -> use a flag or check `if (T)` after the loop

* next time:
  - other approaches:
    - `multiset` + an iterator that moves right by 1 each GET (no rebalance needed if I track it carefully)
    - order-statistic tree (policy-based `tree<>` in GCC) -> `find_by_order(i-1)`
  - watch the output format carefully -> "between" vs "after each" makes a real difference
