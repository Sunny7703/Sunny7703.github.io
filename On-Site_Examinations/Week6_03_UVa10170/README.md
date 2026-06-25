# UVa 10107 - What is the Median?

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10107
- **Problem Title:** What is the Median?
- **Problem Link:** https://onlinejudge.org/external/101/10107.pdf
- **Source Code (Fail):** [src/10107-fail.cpp](./src/10107-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10107-correct.cpp](./src/10107-correct.cpp)

## 2. Problem Statement in My Own Words

- read integers one by one until EOF
- after EACH number, print the current median of all numbers read so far
- odd count -> middle number
- even count -> average of the two middle numbers, INTEGER only (no decimal)
- numbers can be as big as `2^31 - 1`, up to about 10000 of them
- **Goal: print the running median after every input**
  - median needs the numbers in sorted order

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: store everything, sort after each insert, pick the middle
- watch out: even case = `(a + b) / 2`; if `a` and `b` are both near `2^31`, the sum overflows `int` -> use `long long`
- N < 10000 -> `O(n^2)` is fine

### Final Strategy

- keep a sorted `vector<long long> v`
- on each new `x`:
  - push to the back
  - swap it left until it's in the right place (insertion-sort style) -> O(n) per insert
- compute median:
  - if `n` is odd -> `v[n/2]`
  - if `n` is even -> `(v[n/2 - 1] + v[n/2]) / 2` (integer division)
- print
- why it works:
  - keeping `v` sorted makes the middle trivial to find
  - `long long` prevents overflow on the even-case sum
  - integer division naturally drops the fractional part (`.5` -> floor for non-negatives)
- edge cases:
  - just 1 number -> median = that number
  - large values near `2^31` -> need `long long` for the sum
  - leading / trailing spaces in input -> `cin >> x` skips whitespace automatically

## 4. Pseudocode

```text
START
1. v = []
2. while read x:
3. push x to v
4. shift x left until v stays sorted
5. n = size of v
6. if n is odd: mid = v[n/2]
7. else: mid = (v[n/2 - 1] + v[n/2]) / 2
8. print mid
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<long long> v;
    long long x;

    while (cin >> x)
    {



    }
    return 0;
}
```

**Why it failed:**

- only set up the vector and the read loop
- never inserted into `v`, never computed a median, never printed -> no output

### Correct Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<long long> v;
    long long x;

    while (cin >> x)
    {
        // insert keeping the vector sorted (insertion-sort style)
        v.push_back(x);
        for (int i = (int)v.size() - 1; i > 0 && v[i] < v[i - 1]; i--)
            swap(v[i], v[i - 1]);

        int n = (int)v.size();
        long long mid;
        if (n % 2 == 1)
            mid = v[n / 2];                        // odd -> middle one
        else
            mid = (v[n / 2 - 1] + v[n / 2]) / 2;   // even -> integer average

        cout << mid << endl;
    }
    return 0;
}
```

**Why it works:**

- vector stays sorted after every insert -> middle is just an index away
- odd case picks the single middle; even case averages two middles with integer division
- `long long` makes the sum safe even when both middles are near `2^31`
- prints the median after every input -> running median

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> nothing happens | sorted insert + pick middle |
| Edge Cases | none handled | handles odd / even, overflow-safe |
| Output Handling | prints nothing | prints median per input |
| Other | only setup | insertion-sort style insert in O(n) |

### Reflection

- my mistake: stopped after setting up the vector and read loop, no body, no output
- what I learned:
  - keep the data sorted as I go -> median is just an index
  - `int` overflows when two values near `2^31` are added -> use `long long`
  - integer division `/` already drops the fractional part -> matches the spec (no `.5`)

* next time:
  - other approaches worth knowing:
    - sort the whole vector every insert (`O(n log n)` per step) -> simpler but slower
    - two heaps (max-heap for lower half, min-heap for upper half) -> `O(log n)` per step, the classic streaming-median trick
  - always check the value range FIRST to decide `int` vs `long long`
