# UVa 11150 - Cola

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11150
- **Problem Title:** Cola
- **Problem Link:** https://onlinejudge.org/external/111/11150.pdf
- **Source Code (Fail):** [src/11150-fail.cpp](./src/11150-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11150-correct.cpp](./src/11150-correct.cpp)

## 2. Problem Statement in My Own Words

- 3 empty bottles -> 1 new full bottle (drink it -> 1 more empty)
- you can borrow empty bottles, but must give them back at the end
- Input: many `N` lines until end (`N` = bottles you buy, 1..200)
- Output: most bottles you can drink
- **Goal: drink as many as possible by trading empties (and borrowing if it helps)**
  - keep trading 3 empties for 1 new bottle
  - at the very end, if exactly 2 empties left -> borrow 1, trade, drink, give back -> +1

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: drink `N`, then trade empties in a loop
- tricky part: the borrow trick at the end (+1 bottle)
- key question: when can I borrow? -> only when exactly 2 empties are left

### Final Strategy

- `total = N` (drink all first)
- loop while empties `>= 3`:
  - get `empties / 3` new bottles, drink them (add to total)
  - new empties = `empties / 3` (new ones) + `empties % 3` (leftover)
- after the loop, if exactly 2 empties left -> `+1` (borrow trick)
- why it works: borrow only helps with 2 empties (borrow 1 -> 3 -> trade -> drink -> 1 empty -> return)
- edge cases:
  - `N = 1` -> just 1
  - `N = 2` -> 3 (drink 2, then borrow 1)
  - must check leftover AFTER the loop, not at the start

## 4. Pseudocode

```text
START
1. while read n until end:
2.     total = n
3.     while n >= 3:
4.         total += n / 3 // trade empties for new, drink them
5.         n = n / 3 + n % 3 // new empties + leftover empties
6.     if n == 2:
7.         total += 1 // borrow 1, trade, drink, return
8.     print total
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int total = n; // bottles drunk so far

        if (n % 3 == 2) // WRONG: decide borrow straight from n % 3
            total += 1;

        while (n >= 3)
        {
            total += n / 3; // new bottles received, drink them
            n = n / 3 + n % 3; // new empty bottles + leftover empty bottles
        }

        cout << total << endl;
    }
    return 0;
}
```

**Why it failed:**

- borrow check uses `n % 3` of the **original** `n` (before trading) -> wrong moment
- real question = how many empties are left **after** all trading, not at the start
- those two are not the same -> e.g. `n = 10`: ends with 2 empties (can borrow), but `10 % 3 = 1`, so it misses the `+1`
- had to put the check before the loop (the loop overwrites `n`), which makes the "too early" bug clear
- wrong for `n = 4, 5, 10, 30, 40, 100, 150, 190 ...`

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int total = n; // bottles drunk so far

        while (n >= 3)
        {
            total += n / 3; // new bottles received, drink them
            n = n / 3 + n % 3; // new empty bottles + leftover empty bottles
        }

        if (n == 2)
            total += 1; // borrow 1, able to return it

        cout << total << endl;
    }
    return 0;
}
```

**Why it works:**

- trades empties in a loop until fewer than 3 are left
- checks the borrow AFTER the loop, on the real leftover (`n == 2`)
- so the `+1` is added only when borrowing is really possible

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | borrow from `n % 3` of original `n` | borrow from real leftover after loop (`n == 2`) |
| Edge Cases | wrong when leftover is 2 but `n % 3 != 2` (n=4,5,10,...) | right for all `N` (1..200) |
| Output Handling | total off by the missing/extra `+1` | total is correct |
| Other | borrow checked before trading (too early) | borrow checked after trading (right time) |

### Reflection

- my mistake: used `n % 3` of the input to decide borrowing -> too early
- what I learned: the `+1` depends on the leftover AFTER all trades -> simulate first, then check

* next time: watch WHEN I read a value; the final state is not the same as the start state
