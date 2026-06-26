# UVa 12405 - Scarecrow

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 12405
- **Problem Title:** Scarecrow
- **Problem Link:** https://onlinejudge.org/external/124/12405.pdf
- **Source Code (Fail):** [src/12405-fail.cpp](./src/12405-fail.cpp)
- **Source Code (Correct/Accepted):** [src/12405-correct.cpp](./src/12405-correct.cpp)

## 2. Problem Statement in My Own Words

- a row of cells: `.` (fertile) or `#` (infertile)
- a scarecrow placed at position i covers i-1, i, i+1
- **Goal: minimum scarecrows to cover all `.` cells**
  - greedy: scan left to right, place at the first uncovered `.`, then skip 2

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- place minimum scarecrows so every fertile cell is covered

### Final Strategy

- scan left to right
- when we hit a `.`: place a scarecrow here -> covers i-1, i, i+1 -> skip to i+3 (i += 2, then the for loop does i++)
- `#` cells don't need covering -> skip
- why it works: placing at the first uncovered `.` and covering 3 cells forward is optimal (leftmost-first greedy)

## 4. Pseudocode

```text
START
1. count = 0
2. for i = 0..n-1:
3. if s[i] == '.': count++; i += 2
4. print count
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/12405-fail.cpp](./src/12405-fail.cpp))

**Why it failed:**

- read the string but never scanned for fertile cells

### Correct Code

(See [src/12405-correct.cpp](./src/12405-correct.cpp))

**Why it works:**

- greedy: place at first `.`, skip 2 -> each scarecrow covers max 3 cells
- `i += 2` inside the for loop (which also does `i++`) -> effectively jumps 3 positions

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | greedy: place at '.', skip 2 |

### Reflection

- what I learned: "minimum coverage on a 1D line" -> greedy from left to right
- `i += 2` inside a `for(i++)` loop -> total advance is 3 (the coverage radius)

* next time: 1D interval covering -> greedy leftmost-first
