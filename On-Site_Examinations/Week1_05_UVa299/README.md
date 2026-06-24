# UVa 299 - Train Swapping

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 299
- **Problem Title:** Train Swapping
- **Problem Link:** https://onlinejudge.org/external/2/299.pdf
- **Source Code (Fail):** — (correct on the first try, no fail version)
- **Source Code (Correct/Accepted):** [src/299-correct.cpp](./src/299-correct.cpp)

## 2. Problem Statement in My Own Words

- a train has `L` carriages, each with a number
- you may only swap TWO carriages that are NEXT TO each other (adjacent)
- Input: `T` test cases; each = `L`, then `L` numbers
- Output: one line per case -> `Optimal train swapping takes S swaps.`
- **Goal: fewest adjacent swaps to sort the carriages from small to large**
  - = count how many pairs are out of order (inversions)

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- only adjacent swaps allowed -> feels like bubble sort
- key fact: min adjacent swaps = number of inversions (pairs `i < j` with `a[i] > a[j]`)

### Final Strategy

- double loop over all pairs
- my version: if `t[i] > t[k]`, swap them and count -> total count = inversions
- why it works: each out-of-order pair needs exactly 1 swap to fix overall, so counting them gives the minimum
- `L <= 50` -> `O(L^2)` is fast enough
- edge cases:
  - already sorted -> 0 swaps
  - fully reversed -> max swaps `L*(L-1)/2`

## 4. Pseudocode

```text
START
1. read t
2. repeat t times:
3. read l, read l numbers into t[]
4. s = 0
5. for i = 0..l-1:
6. for k = i+1..l-1:
7. if t[i] > t[k]: swap(t[i], t[k]); s++
8. print "Optimal train swapping takes s swaps."
END
```

## 5. Correct Code

No fail version this time -> Accepted on the first try.

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int l;
        cin >> l;
        int t[50];
        for(int i = 0; i < l; i++)
        {
            cin >> t[i];
        }

        int s = 0;
        for(int i = 0; i < l; i++)
        {
            for(int k = i + 1; k < l; k++)
            {
                if(t[i] > t[k])
                {
                    swap(t[i], t[k]);
                    s++;
                }
            }
        }

        cout << "Optimal train swapping takes " << s << " swaps." << endl;
    }
}
```

**Why it works:**

- checks every pair `(i, k)` with `i < k`
- a swap happens exactly once per out-of-order pair -> count = number of inversions
- inversions = the minimum number of adjacent swaps to sort -> correct answer
- output text matches the required format

## 6. Reflection and Other Approaches

### What I Learned

- when only adjacent swaps are allowed, the answer is just the number of inversions
- so the whole problem = "count out-of-order pairs"
- my swap-and-count gives the same number as a plain count-only loop (no need to actually change the array)

### Other Ways to Solve It

| Approach | Idea | Time |
|---|---|---|
| Count only | same double loop, just `if (a[i] > a[j]) count++` (no swap) | `O(L^2)` |
| Bubble sort | swap adjacent pairs until sorted, count each swap | `O(L^2)` |
| Merge sort | count inversions while merging the two halves | `O(L log L)` |
| BIT / Fenwick | for each number, count how many bigger ones came before | `O(L log L)` |

- here `L <= 50`, so `O(L^2)` is more than enough
- for big arrays (like `10^5`), use merge sort or a BIT to stay fast

* next time: if I see "only swap neighbors", think "inversions" right away
