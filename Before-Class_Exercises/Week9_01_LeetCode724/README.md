# LeetCode 724 - Find Pivot Index

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 724
- **Problem Title:** Find Pivot Index
- **Problem Link:** https://leetcode.com/problems/find-pivot-index/description/
- **Source Code (Fail):** [src/lc724-fail.cpp](./src/lc724-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc724-correct.cpp](./src/lc724-correct.cpp)

## 2. Problem Statement in My Own Words

- find an index `i` where `sum of left side == sum of right side`
- left = nums[0..i-1], right = nums[i+1..end], pivot itself is NOT included in either side
- return the LEFTMOST such index, or -1 if none
- **Goal: find pivot where leftSum == rightSum**
  - rightSum = total - leftSum - nums[i]

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- brute force: for each index, compute left sum and right sum -> O(n^2)
- better: compute total sum first, then scan left to right maintaining leftSum

### Final Strategy

- `total = sum of all nums`
- scan from left: at index `i`, `rightSum = total - leftSum - nums[i]`
- if `leftSum == rightSum` -> return `i`
- then `leftSum += nums[i]` and move on
- why it works: rightSum is derived, no need to recompute
- edge cases: pivot at index 0 (leftSum = 0), pivot at last index, negative numbers

## 4. Pseudocode

```text
START
1. total = sum of all nums
2. left = 0
3. for i = 0..n-1:
4. if left == total - left - nums[i]: return i
5. left += nums[i]
6. return -1
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;
        int left = 0;



        return -1;
    }
};
```

**Why it failed:**

- computed total but never scanned for the pivot -> always returns -1

### Correct Code

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int x : nums) total += x;
        int left = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (left == total - left - nums[i]) return i;
            left += nums[i];
        }
        return -1;
    }
};
```

**Why it works:**

- `total - left - nums[i]` gives the right sum without recomputing -> O(n)
- checks BEFORE adding nums[i] to left, so left is purely the left side
- returns the first (leftmost) match

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty scan | scan + compare leftSum vs derived rightSum |
| Edge Cases | none | pivot at 0, negatives, no pivot |
| Output Handling | always -1 | correct index or -1 |
| Other | only setup | O(n) single pass |

### Reflection

- what I learned: "prefix sum" pattern -> compute total first, maintain running left, derive right
- also known as LC 1991 (same problem, different ID)

* next time: if I need leftSum and rightSum, compute one and derive the other from total
