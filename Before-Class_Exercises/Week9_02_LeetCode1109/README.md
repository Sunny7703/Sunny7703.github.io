# LeetCode 1109 - Corporate Flight Bookings

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1109
- **Problem Title:** Corporate Flight Bookings
- **Problem Link:** https://leetcode.com/problems/corporate-flight-bookings/
- **Source Code (Fail):** [src/lc1109-fail.cpp](./src/lc1109-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc1109-correct.cpp](./src/lc1109-correct.cpp)

## 2. Problem Statement in My Own Words

- `n` flights (1-indexed), many bookings `[first, last, seats]`
- each booking adds `seats` to flights `first` through `last`
- return an array `answer[i]` = total seats booked on flight `i+1`
- **Goal: apply range-add operations efficiently -> difference array + prefix sum**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- brute force: for each booking, loop from first to last and add seats -> O(bookings * n)
- better: difference array -> each booking is just 2 operations, then one prefix sum pass

### Final Strategy

- `diff[n+1]` array, all zeros
- for each booking `[f, l, s]`: `diff[f-1] += s`, `diff[l] -= s` (if l < n)
- prefix sum of `diff` gives the answer
- why it works: +s at start means "from here onward, add s"; -s after end cancels it
- edge cases: booking covers the whole range (no -s needed at the end)

## 4. Pseudocode

```text
START
1. diff[n+1] = all 0
2. for each booking [f, l, s]:
3. diff[f-1] += s
4. if l < n: diff[l] -= s
5. ans[0] = diff[0]
6. for i = 1..n-1: ans[i] = ans[i-1] + diff[i]
7. return ans
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);



        return {};
    }
};
```

**Why it failed:**

- created the diff array but never filled it or computed prefix sums

### Correct Code

```cpp
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);
        for (auto& b : bookings) {
            diff[b[0] - 1] += b[2];
            if (b[1] < n) diff[b[1]] -= b[2];
        }
        vector<int> ans(n);
        ans[0] = diff[0];
        for (int i = 1; i < n; i++) ans[i] = ans[i-1] + diff[i];
        return ans;
    }
};
```

**Why it works:**

- difference array turns range-add into two point operations -> O(1) per booking
- prefix sum reconstructs the actual values -> O(n)
- total: O(bookings + n)

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | difference array + prefix sum |
| Edge Cases | none | handles boundary (l == n) |
| Output Handling | returns empty | returns correct totals |
| Other | only setup | O(bookings + n) instead of O(bookings * n) |

### Reflection

- what I learned: "add X to a range [L, R]" repeated many times -> difference array pattern
- the trick: +X at L, -X at R+1, then prefix sum gives final values

* next time: whenever I see "range update + final query", think difference array
