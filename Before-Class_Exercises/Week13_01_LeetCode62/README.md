# LeetCode 62 - Unique Paths

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 62
- **Problem Title:** Unique Paths
- **Problem Link:** https://leetcode.com/problems/unique-paths/description/
- **Source Code (Fail):** [src/lc62-fail.cpp](./src/lc62-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc62-correct.cpp](./src/lc62-correct.cpp)

## 2. Problem Statement in My Own Words

- `m x n` grid, start at top-left, goal is bottom-right
- can only move RIGHT or DOWN
- **Goal: count total number of unique paths**
  - classic DP: `dp[i][j] = dp[i-1][j] + dp[i][j-1]`

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- each cell can only be reached from above or from the left
- first row and first column: only 1 way (straight line)

### Final Strategy

- `dp[m][n]`, init all to 1 (first row and first col have only 1 path each)
- for `i >= 1, j >= 1`: `dp[i][j] = dp[i-1][j] + dp[i][j-1]`
- return `dp[m-1][n-1]`
- why it works: each cell sums the ways from above and from the left
- edge cases: 1x1 grid (1 path), 1xn or mx1 (1 path)
- also solvable with math: `C(m+n-2, m-1)` (choose m-1 downs out of m+n-2 moves)

## 4. Pseudocode

```text
START
1. dp[m][n] = all 1
2. for i = 1..m-1:
3. for j = 1..n-1:
4. dp[i][j] = dp[i-1][j] + dp[i][j-1]
5. return dp[m-1][n-1]
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));



        return dp[m-1][n-1];
    }
};
```

**Why it failed:**

- initialized dp to all 1 but never filled in the inner cells -> returns 1 for everything

### Correct Code

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        return dp[m-1][n-1];
    }
};
```

**Why it works:**

- first row / col stay 1 (correct: only 1 path along the edge)
- inner cells sum up + left -> counts all paths
- `dp[m-1][n-1]` is the answer

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | no inner fill | dp[i][j] = up + left |
| Edge Cases | always 1 | 1x1 = 1 (correct), larger grids correct |
| Output Handling | wrong | right |
| Other | only init | O(m*n) time and space |

### Reflection

- what I learned: grid path counting = classic 2D DP; init edges to 1, fill the rest
- also: math formula C(m+n-2, m-1) gives the same answer in O(min(m,n))

* next time: "how many ways to go from top-left to bottom-right" -> 2D DP or combinatorics
