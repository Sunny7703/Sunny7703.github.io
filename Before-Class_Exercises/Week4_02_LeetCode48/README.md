# LeetCode 48 - Rotate Image

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 48
- **Problem Title:** Rotate Image
- **Problem Link:** https://leetcode.com/problems/rotate-image/description/
- **Source Code (Fail):** [src/lc48-fail.cpp](./src/lc48-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc48-correct.cpp](./src/lc48-correct.cpp)

## 2. Problem Statement in My Own Words

- given an `n x n` matrix
- rotate it 90 degrees CLOCKWISE
- must do it IN PLACE (no new matrix)
- Input: `vector<vector<int>>` matrix
- Output: nothing (mutate the input)
- **Goal: turn the matrix 90 degrees clockwise without allocating another matrix**
  - new pos: `matrix[i][j]` ends up at `matrix[j][n-1-i]`

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: use a second matrix and copy `matrix[i][j]` to `result[j][n-1-i]` -> easy but uses O(n^2) space, NOT in place
- in-place trick: split rotation into TWO simpler in-place steps:
  1. transpose (flip across main diagonal): `m[i][j] <-> m[j][i]`
  2. reverse each row: `m[i] -> reversed(m[i])`
- doing both in this order = clockwise 90

### Final Strategy

- step 1: transpose
  - for `i` in `0..n-1`, for `j` in `i+1..n-1`: swap `m[i][j]` and `m[j][i]`
  - (swap only the upper triangle so each pair is swapped once, not twice)
- step 2: reverse each row
  - for `i` in `0..n-1`: reverse `m[i]`
- why it works:
  - transpose maps `(i, j) -> (j, i)`
  - row reverse maps `(j, i) -> (j, n-1-i)`
  - combined: `(i, j) -> (j, n-1-i)` -> exactly clockwise 90
- edge cases:
  - `n = 1` -> transpose and reverse do nothing -> correct
  - even `n` (e.g. 4) -> the upper triangle has no diagonal cells, all swaps are real
  - odd `n` -> the middle row's middle cell stays in place

## 4. Pseudocode

```text
START
1. n = size of matrix
2. transpose:
3. for i = 0..n-1:
4. for j = i+1..n-1: swap m[i][j] with m[j][i]
5. reverse each row:
6. for i = 0..n-1: reverse m[i]
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();



    }
};
```

**Why it failed:**

- only set up `n`
- never did the transpose, never reversed rows -> matrix is unchanged

### Correct Code

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // step 1: transpose -> swap matrix[i][j] with matrix[j][i] (i < j)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

        // step 2: reverse each row -> result is clockwise 90 degrees
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
```

**Why it works:**

- transpose swaps across the main diagonal, mapping `(i, j) -> (j, i)`
- reversing each row then maps `(j, i) -> (j, n-1-i)`
- combined effect: `(i, j) -> (j, n-1-i)` = clockwise 90
- swap loop uses `j > i` so each pair is swapped exactly once -> no double-swap
- everything is done in place -> O(1) extra space (besides the temp in `swap`)

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> matrix unchanged | transpose, then reverse each row |
| Edge Cases | none handled | works for n = 1 too (loops just don't run) |
| Output Handling | mutates nothing | mutates the input in place (as required) |
| Other | only setup | O(n^2) time, O(1) extra space |

### Reflection

- my mistake: stopped at saving `n`, didn't do any of the rotation
- what I learned:
  - "rotate 90 clockwise in place" = transpose + reverse each row
  - "rotate 90 counter-clockwise in place" = transpose + reverse each COLUMN (or reverse rows first, then transpose)
  - swap loop must use `j > i` (or `j < i`) -> if you do all `(i, j)`, every pair gets swapped twice and ends back where it started

* next time:
  - whenever a square matrix needs rotation, think of it as 2 axis flips
  - 180 in place = reverse rows + reverse columns; can also be `m[i][j] <-> m[n-1-i][n-1-j]` for the upper half
  - to swap, use `std::swap` -> no temp variable needed
