# LeetCode 169 - Majority Element

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 169
- **Problem Title:** Majority Element
- **Problem Link:** https://leetcode.com/problems/majority-element/
- **Source Code (Fail):** [src/lc169-fail.cpp](./src/lc169-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc169-correct.cpp](./src/lc169-correct.cpp)

## 2. Problem Statement in My Own Words

- given `nums` (size `n`), one value appears MORE THAN `n / 2` times -> the "majority"
- the problem guarantees the majority always exists
- Input: `vector<int>` `nums`
- Output: the majority element
- **Goal: find the value that appears > n/2 times in one pass with O(1) extra space**
  - because it's more than half, it always "wins" a pair-by-pair cancellation game

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: count each number with a hash map, then pick the one with count > n/2 -> O(n) time and O(n) space
- smarter: Boyer-Moore voting -> O(n) time, O(1) space
- the trick: pair up different values and cancel them -> the majority always survives

### Final Strategy

- keep two variables:
  - `cand` (current candidate)
  - `count` (how many "votes" left for it)
- walk through `nums`:
  - if `count == 0` -> pick `x` as new candidate, `count = 1`
  - else if `x == cand` -> `count++` (one more vote)
  - else -> `count--` (one vote against)
- return `cand` at the end
- why it works:
  - every time `count` goes down to 0, you've matched the candidate with the SAME number of opposing votes
  - the true majority has MORE than half -> it can never be fully cancelled
  - so the last surviving candidate has to be the majority
- edge cases:
  - single element -> it's the majority
  - all same elements -> count just grows
  - candidate gets "knocked out" mid-way -> a new candidate takes over; the real majority will come back

## 4. Pseudocode

```text
START
1. cand = 0, count = 0
2. for x in nums:
3. if count == 0: cand = x; count = 1
4. else if x == cand: count += 1
5. else: count -= 1
6. return cand
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = 0, count = 0;



    }
};
```

**Why it failed:**

- only set up the variables `cand` and `count`
- never walked through `nums`, never returned anything -> compile error (no return on a non-void function) / undefined behaviour

### Correct Code

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Boyer-Moore majority vote: O(n) time, O(1) space
        int cand = 0, count = 0;
        for (int x : nums) {
            if (count == 0) { cand = x; count = 1; }
            else if (x == cand) count++;
            else                count--;
        }
        return cand;
    }
};
```

**Why it works:**

- walks the array once and maintains a single candidate
- pair-by-pair cancellation drops both sides equally; the majority has more than half, so it cannot be fully cancelled
- final `cand` is guaranteed to be the majority (the problem promises it exists)

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> nothing happens | Boyer-Moore voting |
| Edge Cases | none handled | single element, all same, candidate swaps -> all handled |
| Output Handling | no return | returns the surviving candidate |
| Other | only setup | O(n) time, O(1) space |

### Reflection

- my mistake: stopped at the variable setup
- what I learned:
  - "more than half" -> pair-up cancellation works -> Boyer-Moore
  - intuition: every "vote down" pairs the candidate with one opposing vote; the majority owns more pairs than everyone else combined, so it always survives
  - return value matters: missing `return` in a non-void function is undefined behaviour

* next time:
  - other approaches worth knowing:
    - hash map count -> O(n) time, O(n) space; works even WITHOUT the "majority exists" guarantee (just check count > n/2)
    - sort and return `nums[n/2]` -> O(n log n) time, O(1) extra; nice short answer if sorting is allowed
    - if the guarantee is NOT given, do a second pass to verify the candidate before returning it
