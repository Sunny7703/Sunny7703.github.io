# LeetCode 64 - Minimum Path Sum

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 64
- **Problem Title:** Minimum Path Sum
- **Problem Link:** https://leetcode.com/problems/minimum-path-sum/description/
- **Source Code (Fail):** [src/lc64-fail.cpp](./src/lc64-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc64-correct.cpp](./src/lc64-correct.cpp)

## 2. Problem Statement in My Own Words

- `m x n` grid with non-negative numbers
- move only RIGHT or DOWN from top-left to bottom-right
- **Goal: find the path with the smallest total sum**
  - like LC 62 but with weighted cells -> `dp[i][j] = grid[i][j] + min(up, left)`

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- similar to Unique Paths but now minimizing sum instead of counting
- can modify the grid in place (no extra space needed)

### Final Strategy

- first column: each cell += the one above (only way is straight down)
- first row: each cell += the one to the left (only way is straight right)
- inner cells: `grid[i][j] += min(grid[i-1][j], grid[i][j-1])`
- answer at `grid[m-1][n-1]`
- why it works: optimal substructure -> best path to (i,j) must come from the better of (i-1,j) or (i,j-1)
- edge cases: 1x1 grid, single row, single column

## 4. Pseudocode

```text
START
1. for i = 1..m-1: grid[i][0] += grid[i-1][0]
2. for j = 1..n-1: grid[0][j] += grid[0][j-1]
3. for i = 1..m-1:
4. for j = 1..n-1:
5. grid[i][j] += min(grid[i-1][j], grid[i][j-1])
6. return grid[m-1][n-1]
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();



        return grid[m-1][n-1];
    }
};
```

**Why it failed:**

- never accumulated the path sums -> returns just the bottom-right cell value

### Correct Code

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 1; i < m; i++) grid[i][0] += grid[i-1][0];
        for (int j = 1; j < n; j++) grid[0][j] += grid[0][j-1];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        return grid[m-1][n-1];
    }
};
```

**Why it works:**

- edges can only come from one direction -> cumulative sum
- inner cells pick the cheaper path (up or left) -> greedy within DP
- modifies grid in place -> O(1) extra space

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | DP: edges cumulative, inner = cell + min(up, left) |
| Edge Cases | wrong for all grids > 1x1 | handles edges and inner cells |
| Output Handling | returns raw cell value | returns accumulated min sum |
| Other | only setup | O(m*n) time, O(1) extra space |

### Reflection

- what I learned: LC 62 (count paths) and LC 64 (min path sum) share the same DP structure, just different operations (sum vs min)
- modifying the grid in place saves memory

* next time: "grid + move right/down + optimize something" -> 2D DP on the grid itself
