# LeetCode 1700 - Number of Students Unable to Eat Lunch

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1700
- **Problem Title:** Number of Students Unable to Eat Lunch
- **Problem Link:** https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
- **Source Code (Fail):** [src/lc1700-fail.cpp](./src/lc1700-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc1700-correct.cpp](./src/lc1700-correct.cpp)

## 2. Problem Statement in My Own Words

- students in a queue, sandwiches in a stack; each is type 0 or 1
- front student takes the top sandwich if it matches, else goes to back of queue
- stops when NO student in the queue wants the top sandwich
- **Goal: how many students can't eat?**
  - key insight: student ORDER doesn't matter -> only COUNTS of 0s and 1s matter

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- simulate the queue rotation -> works but slow for edge cases
- smarter: count how many want 0 and how many want 1; go through sandwiches top to bottom

### Final Strategy

- count students who want 0 and who want 1
- for each sandwich (top to bottom): if someone wants it -> serve (decrement count); if nobody wants it -> everyone left is stuck
- the number stuck = total remaining sandwiches from that point
- why it works: order in the queue doesn't matter because the queue rotates; the process stops when the top sandwich has zero matching students
- edge cases: all same type, everyone eats, nobody eats the first sandwich

## 4. Pseudocode

```text
START
1. count[0] = number of 0-students, count[1] = number of 1-students
2. for i = 0..n-1:
3. if count[sandwiches[i]] == 0: return n - i (everyone left is stuck)
4. count[sandwiches[i]]--
5. return 0
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        for (int s : students) count[s]++;



        return 0;
    }
};
```

**Why it failed:**

- counted students but never scanned the sandwiches

### Correct Code

```cpp
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        for (int s : students) count[s]++;
        for (int i = 0; i < (int)sandwiches.size(); i++) {
            if (count[sandwiches[i]] == 0) return (int)sandwiches.size() - i;
            count[sandwiches[i]]--;
        }
        return 0;
    }
};
```

**Why it works:**

- once no one wants the top sandwich, all remaining students are stuck (the queue just rotates forever)
- counting removes the need to simulate rotations -> O(n)

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty scan | count + scan sandwiches |
| Edge Cases | none | deadlock detection |
| Output Handling | always 0 | correct stuck count |
| Other | only setup | O(n), no simulation needed |

### Reflection

- what I learned: "circular queue + stop condition" can often be simplified by counting; student order is irrelevant here

* next time: before simulating, ask "does the order actually matter?" -> if not, just count
