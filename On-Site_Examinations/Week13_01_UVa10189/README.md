# UVa 10189 - Minesweeper

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10189
- **Problem Title:** Minesweeper
- **Problem Link:** https://onlinejudge.org/external/101/10189.pdf
- **Source Code (Fail):** [src/10189-fail.cpp](./src/10189-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10189-correct.cpp](./src/10189-correct.cpp)

## 2. Problem Statement in My Own Words

- `n x m` grid with `*` (mine) and `.` (safe)
- for each safe cell, count how many of its 8 neighbors are mines
- Output: the board with numbers replacing `.`, mines stay `*`
- **Goal: for each `.`, count `*` in the 8 surrounding cells**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- generate a Minesweeper board: each non-mine cell shows the count of adjacent mines

### Final Strategy

- read the grid
- for each cell: if mine, print `*`; else count adjacent mines using dx/dy arrays
- 8 directions: `(-1,-1), (-1,0), (-1,1), (0,-1), (0,1), (1,-1), (1,0), (1,1)`
- bounds check before accessing neighbors
- blank line between cases (not after the last)

## 4. Pseudocode

```text
START
1. for each cell (i, j):
2. if mine: print '*'
3. else: count = number of '*' in 8 neighbors; print count
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/10189-fail.cpp](./src/10189-fail.cpp))

**Why it failed:**

- read the grid but never counted or printed

### Correct Code

(See [src/10189-correct.cpp](./src/10189-correct.cpp))

**Why it works:**

- dx/dy arrays make the 8-neighbor check clean
- bounds check prevents out-of-range access
- blank line between fields (using a `caseNum` flag)

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | 8-directional neighbor count with bounds check |

### Reflection

- what I learned: grid neighbor counting -> use dx/dy direction arrays instead of 8 separate if-blocks
- blank line "between" cases -> check if it's not the first case before printing

* next time: any grid neighbor problem -> dx/dy arrays
