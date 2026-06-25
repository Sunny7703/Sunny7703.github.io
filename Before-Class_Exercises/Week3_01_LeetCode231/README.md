# LeetCode 231 - Power of Two

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 231
- **Problem Title:** Power of Two
- **Problem Link:** https://leetcode.com/problems/power-of-two/
- **Source Code (Fail):** [src/lc231-fail.cpp](./src/lc231-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc231-correct.cpp](./src/lc231-correct.cpp)

## 2. Problem Statement in My Own Words

- given an `int n`, return true if `n` is a power of two
- powers of two: 1, 2, 4, 8, 16, ... (i.e. `2^k` for some `k >= 0`)
- Input range: `-2^31 <= n <= 2^31 - 1` (so negative numbers and 0 can appear)
- **Goal: tell if `n == 2^k` for some non-negative `k`**
  - n must be POSITIVE (0 and negatives -> false)
  - in binary, a power of two has EXACTLY one `1` bit

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- loop idea: keep dividing by 2 until `n == 1`; if any step has a remainder, it's not a power of two
- no-loop idea (smarter): a power of two has exactly one `1` bit in binary -> use the bit trick `n & (n - 1) == 0`

### Final Strategy

- one-liner with bits:
  - `n > 0` -> rules out 0 and negatives (very important: INT_MIN has bit pattern `1000...0` which looks like a single bit, but it's negative)
  - `(n & (n - 1)) == 0` -> for any positive `n`, this is true iff `n` has exactly one bit set
- why it works:
  - subtracting 1 from a number flips the lowest set bit to 0 and turns every bit below it to 1
  - so AND-ing them clears that lowest bit
  - if there was only one set bit, the result is 0
  - examples:
    - `8 = 1000`, `7 = 0111`, `8 & 7 = 0` -> power of two
    - `12 = 1100`, `11 = 1011`, `12 & 11 = 1000` (not 0) -> not
- edge cases:
  - `n = 1` -> `2^0`, true; `1 & 0 = 0` -> true
  - `n = 0` -> not positive -> false (`n > 0` blocks it)
  - `n < 0` -> false (`n > 0` blocks it)
  - `n = INT_MIN` (`1000...0`, looks like a single bit) -> false because negative

## 4. Pseudocode

```text
START
1. isPowerOfTwo(n):
2. return (n > 0) AND ((n & (n - 1)) == 0)
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool r = true;
        while(n != 1)
        {
            if(n % 2 == 1)
            {
                true = false;
                return r;
            }
            n /= 2;
        }
        return r;
    }
    int main()
    {
        int n;
        cin >> n;
        bool r = isPowerOfTwo(n);
        cout << r << endl;
    }
};
```

**Why it failed:**

- `true = false;` -> `true` is a built-in literal, NOT a variable; cannot assign to it -> compile error
  - meant to write `r = false;` (or just `return false;`)
- `int main()` is INSIDE the class -> LeetCode does not need a `main` and member-function syntax is wrong here
- no check for `n <= 0`:
  - `n = 0` -> `while (0 != 1)` is true, `0 / 2 = 0` -> INFINITE LOOP (TLE or hang)
  - `n < 0` -> can also loop forever depending on the value
- even if `true = false` is fixed, the structure `if (n % 2 == 1) { r = false; return r; }` is OK in spirit, but `return false;` is cleaner and avoids touching `r`
- the algorithm idea (keep dividing by 2) is fine, but you need:
  - `if (n <= 0) return false;` first
  - swap `true = false` for `return false` (or `r = false`)
  - put `main` OUTSIDE the class, or just remove it (LeetCode doesn't need it)

### Correct Code

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // power of two: positive AND has exactly one '1' bit
        // n & (n - 1) clears the lowest set bit; if the result is 0,
        // there was only one bit -> n is a power of two
        return n > 0 && (n & (n - 1)) == 0;
    }
};
```

**Why it works:**

- `n > 0` handles 0, negatives, and the `INT_MIN` trap in one shot
- `(n & (n - 1)) == 0` is the classic "exactly one bit set" test
- runs in O(1), no loop, no division
- short-circuit `&&` -> if `n <= 0` we never even compute the bit op

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code (loop) | Correct Code (bit trick) |
|---|---|---|
| Logic | divide by 2 until 1; bail on odd remainder | check "single bit" with `n & (n-1)` |
| Edge Cases | misses `n <= 0` -> infinite loop on `n = 0` | `n > 0` covers 0, negatives, and `INT_MIN` |
| Output Handling | `true = false` is a compile error; `main` inside class | clean one-liner, no `main` needed for LeetCode |
| Other | O(log n) time | O(1) time |

### Loop vs No-Loop (the two approaches)

- the LOOP idea is fine in principle:
  - check `n <= 0 -> false`
  - divide by 2 in a loop; the moment you see an odd remainder (`n % 2 == 1`) and `n != 1`, return false
  - end at `n == 1` -> true
- the BIT TRICK is much shorter and runs in O(1):
  - rests on the fact that subtracting 1 turns the lowest set bit to 0 and all bits below it to 1
  - so `n & (n-1)` zeroes out the lowest set bit; if that gives 0, there was only one bit -> power of two
- both give the same answers across all the edge cases (`1, 0, -1, INT_MIN, INT_MAX, 1<<30`)
- on LeetCode, both should AC for this problem; the bit trick is just cleaner and constant time

### Reflection

- my mistakes (loop version):
  - tried to assign to the literal `true` -> compile error
  - put `main` inside the class -> wrong place
  - forgot the `n <= 0` guard -> `n = 0` is an infinite loop
- what I learned:
  - `true` / `false` are values, not variables; only variables (like `r`) can be on the LEFT of `=`
  - on LeetCode, just write the class method; no `main`, no `cin`, no `cout`
  - always think about the input range first; "negative or zero" is the most common silent bug

* next time:
  - read the constraints (`-2^31 <= n <= 2^31 - 1`) BEFORE coding -> remember to handle 0 and negatives
  - when "exactly one bit" or "is a power of two" comes up, reach for `n & (n - 1)`
