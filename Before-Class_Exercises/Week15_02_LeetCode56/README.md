# LeetCode 56 - Merge Intervals

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 56
- **Problem Title:** Merge Intervals
- **Problem Link:** https://leetcode.com/problems/merge-intervals/description/
- **Source Code (Fail):** [src/lc56-fail.cpp](./src/lc56-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc56-correct.cpp](./src/lc56-correct.cpp)

## 2. Problem Statement in My Own Words

- given a list of intervals `[start, end]`
- merge all overlapping intervals
- return the merged list
- **Goal: sort by start, then merge overlapping neighbors**
  - two intervals overlap if the new start <= the previous end

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- sort by start time first -> overlapping intervals become adjacent
- then scan and merge

### Final Strategy

- sort intervals by start
- maintain a result list; for each interval:
  - if it overlaps with the last result interval (`iv[0] <= res.back()[1]`): extend the end to `max(res.back()[1], iv[1])`
  - else: push as a new interval
- why it works: after sorting, if interval `i` doesn't overlap with the current merged block, no later interval can either (their starts are >= iv[0])
- edge cases: single interval, all disjoint, all overlapping, contained intervals like `[1,10], [2,3]`

## 4. Pseudocode

```text
START
1. sort intervals by start
2. res = []
3. for each interval iv:
4. if res not empty and iv[0] <= res.back()[1]: res.back()[1] = max(res.back()[1], iv[1])
5. else: push iv to res
6. return res
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;



        return res;
    }
};
```

**Why it failed:**

- sorted but never merged -> returns empty

### Correct Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for (auto& iv : intervals) {
            if (!res.empty() && iv[0] <= res.back()[1])
                res.back()[1] = max(res.back()[1], iv[1]);
            else
                res.push_back(iv);
        }
        return res;
    }
};
```

**Why it works:**

- sorting ensures overlapping intervals are adjacent
- `iv[0] <= res.back()[1]` catches overlaps AND touching intervals
- `max(res.back()[1], iv[1])` handles contained intervals (where the new end is smaller)

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | sort + scan + merge overlaps |
| Edge Cases | none | contained, touching, disjoint |
| Output Handling | returns empty | returns merged list |
| Other | only sort | O(n log n) for sort, O(n) for scan |

### Reflection

- what I learned: "merge overlapping intervals" is a classic: sort by start, then greedily extend or push
- the `max` in the extend step is easy to forget -> without it, `[1,10],[2,3]` would shrink to `[1,3]` (wrong)

* next time: "merge intervals" -> sort + greedy; remember `max` for the end
