# LeetCode 228 - Summary Ranges

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 228
- **Problem Title:** Summary Ranges
- **Problem Link:** https://leetcode.com/problems/summary-ranges/description/
- **Source Code (Fail):** [src/lc228-fail.cpp](./src/lc228-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc228-correct.cpp](./src/lc228-correct.cpp)

## 2. Problem Statement in My Own Words

- sorted unique integers -> group consecutive numbers into ranges
- `"a->b"` for a range, `"a"` for a single number
- **Goal: merge consecutive numbers into range strings**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- scan left to right, extend while next = current + 1
- when the chain breaks, output the range

### Final Strategy

- for each `i`: record `start = nums[i]`
- while `nums[i+1] == nums[i] + 1`: advance `i`
- if `start == nums[i]`: single number -> `"start"`
- else: range -> `"start->nums[i]"`
- why it works: the array is sorted and unique -> consecutive = differ by 1
- edge cases: empty array, single element, all consecutive, no consecutive

## 4. Pseudocode

```text
START
1. for i = 0..n-1:
2. start = nums[i]
3. while i+1 < n and nums[i+1] == nums[i]+1: i++
4. if start == nums[i]: push "start"
5. else: push "start->nums[i]"
6. return result
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();



        return res;
    }
};
```

**Why it failed:**

- never scanned -> returns empty

### Correct Code

```cpp
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int start = nums[i];
            while (i + 1 < n && nums[i+1] == nums[i] + 1) i++;
            if (nums[i] == start)
                res.push_back(to_string(start));
            else
                res.push_back(to_string(start) + "->" + to_string(nums[i]));
        }
        return res;
    }
};
```

**Why it works:**

- inner while extends the range as long as consecutive
- `i` advances inside the while -> outer for naturally moves past the range
- `to_string` handles the formatting

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | extend consecutive, format range |
| Edge Cases | none | single number vs range |
| Output Handling | returns empty | returns correct strings |
| Other | only setup | O(n) single pass |

### Reflection

- what I learned: "group consecutive" = two-pointer with inner advancement of `i`
- careful: `i` is modified inside the inner while AND the outer for -> works because for's `i++` moves past the last element of the range

* next time: "group sorted numbers into ranges" -> scan + extend pattern
