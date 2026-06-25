# LeetCode 1046 - Last Stone Weight

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1046
- **Problem Title:** Last Stone Weight
- **Problem Link:** https://leetcode.com/problems/last-stone-weight/description/
- **Source Code (Fail):** [src/lc1046-fail.cpp](./src/lc1046-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc1046-correct.cpp](./src/lc1046-correct.cpp)

## 2. Problem Statement in My Own Words

- each round: smash the 2 heaviest stones; if same weight both destroyed, else the lighter is destroyed and the heavier shrinks by the lighter's weight
- repeat until 0 or 1 stone left
- **Goal: return the last stone's weight (or 0 if none left)**
  - need to repeatedly find the 2 largest -> max-heap

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- sort + pick last two each round -> O(n^2 log n)
- better: max-heap -> O(n log n) total

### Final Strategy

- put all stones into a max-heap (`priority_queue<int>`)
- while size > 1: pop two (`a >= b`); if `a != b` push `a - b`
- return top (or 0 if empty)
- why it works: heap always gives the two heaviest in O(log n)
- edge cases: all stones same weight (all pairs cancel), single stone

## 4. Pseudocode

```text
START
1. pq = max-heap from stones
2. while pq.size > 1:
3. a = pop, b = pop
4. if a != b: push a - b
5. return pq empty ? 0 : pq.top
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());



        return pq.empty() ? 0 : pq.top();
    }
};
```

**Why it failed:**

- built the heap but never smashed any stones

### Correct Code

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if (a != b) pq.push(a - b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};
```

**Why it works:**

- max-heap always gives the two heaviest stones
- push the remainder back if not equal
- stops when 0 or 1 stone left

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | no smashing | pop two, push remainder |
| Edge Cases | returns largest stone | returns correct last weight or 0 |
| Output Handling | wrong | right |
| Other | only setup | O(n log n) |

### Reflection

- what I learned: "repeatedly find/remove the max" -> max-heap (`priority_queue`)
- LC 1046 is the easy version; LC 1049 (Last Stone Weight II) is the hard version (subset-sum DP)

* next time: "simulate a process that always picks the biggest" -> heap
