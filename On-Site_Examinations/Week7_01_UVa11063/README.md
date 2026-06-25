# UVa 11063 - B2-Sequences

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11063
- **Problem Title:** B2-Sequences
- **Problem Link:** https://onlinejudge.org/external/110/11063.pdf
- **Source Code (Fail):** [src/11063-fail.cpp](./src/11063-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11063-correct.cpp](./src/11063-correct.cpp)

## 2. Problem Statement in My Own Words

- read `N`, then `N` numbers `b[0]..b[N-1]`; stop when `N < 2`
- a B2-sequence needs BOTH:
  1. strictly increasing: `b[0] < b[1] < ... < b[N-1]`
  2. all pair-sums `b[i] + b[j]` (with `i <= j`) are different
- Output: `Case #X: It is a B2-Sequence.` or `It is not a B2-Sequence.`, then a blank line
- **Goal: check both conditions; if either fails -> not a B2-sequence**
  - pair-sums include `i == j`, i.e. `b[i] + b[i]`

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: just check all pair-sums are unique
- forgot: the sequence ALSO has to be strictly increasing -> two conditions, not one
- pair count = `N*(N+1)/2`, small N -> O(N^2) is fine

### Final Strategy

- read N and the N numbers
- check 1: loop `i = 1..N-1`, if `b[i] <= b[i-1]` -> not B2
- check 2: a `sum[20005]` table; for each pair `(i, j)` with `j >= i`, if `sum[b[i]+b[j]]` already set -> not B2; else mark it
- if both checks pass -> is B2
- why it works:
  - strictly increasing means no two values are equal AND order matters -> must check it on its own
  - the table makes "have I seen this sum before?" an O(1) lookup
- edge cases:
  - N < 2 -> stop reading
  - pair includes `b[i] + b[i]` (j starts at i, not i+1)
  - non-increasing input with unique pair-sums -> would slip through if check 1 is missing
  - print a blank line after each case

## 4. Pseudocode

```text
START
1. case = 1
2. while read n and n >= 2:
3. read b[0..n-1]
4. ok = true
5. for i = 1..n-1: if b[i] <= b[i-1]: ok = false; break
6. clear sum[]
7. for i = 0..n-1 (while ok):
8. for j from n-1 down to i:
9. s = b[i] + b[j]
10. if sum[s]: ok = false; break
11. sum[s] = 1
12. print "Case #case: It is [not ]a B2-Sequence."
13. print blank line
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int caseNum = 1;
    while(cin >> n)
    {
        if(n < 2)
            break;

        int b[100] = {};
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        bool ok = true;

        // (forgot to check strictly increasing here)

        int sum[20005] = {};

        for(int i = 0; i < n && ok; i++)
        {
            for(int j = n - 1; j >= i; j--)
            {
                int s = b[i] + b[j];

                if(sum[s])
                {
                    ok = false;
                    break;
                }

                sum[s] = 1;
            }
        }

        cout << "Case #" << caseNum++;
        if(!ok)
            cout << ": It is not a B2-Sequence." << endl;
        else
            cout << ": It is a B2-Sequence." << endl;
        cout << endl;
    }

    return 0;
}
```

**Why it failed:**

- only checks the pair-sums; forgot the strictly-increasing rule
- a non-increasing input whose pair-sums all differ -> wrongly says "is a B2-Sequence"
- example: `3` numbers `2 1 5`
  - sums: 2+2=4, 2+1=3, 2+5=7, 1+1=2, 1+5=6, 5+5=10 -> all different
  - fail prints `is a B2-Sequence` (wrong)
  - correct prints `is not a B2-Sequence` (right, because 2 > 1)
- on inputs that ARE strictly increasing, fail and correct agree -> bug only shows on tricky cases

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    int caseNum = 1;
    while(cin >> n)
    {
        if(n < 2)
            break;

        int b[100] = {};
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        bool ok = true;

        for(int i = 1; i < n; i++)
        {
            if(b[i] <= b[i - 1])
            {
                ok = false;
                break;
            }
        }

        int sum[20005] = {};

        for(int i = 0; i < n && ok; i++)
        {
            for(int j = n - 1; j >= i; j--)
            {
                int s = b[i] + b[j];

                if(sum[s])
                {
                    ok = false;
                    break;
                }

                sum[s] = 1;
            }
        }

        cout << "Case #" << caseNum++;
        if(!ok)
            cout << ": It is not a B2-Sequence." << endl;
        else
            cout << ": It is a B2-Sequence." << endl;
        cout << endl;
    }

    return 0;
}
```

**Why it works:**

- check 1: strictly increasing -> if `b[i] <= b[i-1]` anywhere, fail right away
- check 2: only runs when check 1 passed (`ok` still true)
- `sum[]` table marks each seen pair-sum; a second hit -> fail
- pair loop uses `j >= i`, so it includes `b[i] + b[i]` (B2 needs that too)
- both checks must pass -> is B2

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | only pair-sum uniqueness | strictly increasing AND pair-sum uniqueness |
| Edge Cases | misses non-increasing inputs with unique sums | catches both rule violations |
| Output Handling | same format | same format |
| Other | a quick check skipped to save lines | small loop, big safety net |

### Reflection

- my mistake: read the spec but only coded ONE of the two conditions; assumed "unique sums" was enough
- what I learned: when a definition lists multiple conditions, write a check for EACH one and AND them together
- the bug is silent on easy tests (most sample inputs are already increasing) -> easy to think it works when it doesn't

* next time: list every condition from the spec as a TODO before coding, and tick them off one by one
