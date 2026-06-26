# UVa 490 - Rotating Sentences

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 490
- **Problem Title:** Rotating Sentences
- **Problem Link:** https://onlinejudge.org/external/4/490.pdf
- **Source Code (Fail):** [src/490-fail.cpp](./src/490-fail.cpp)
- **Source Code (Correct/Accepted):** [src/490-correct.cpp](./src/490-correct.cpp)

## 2. Problem Statement in My Own Words

- read multiple lines of text
- rotate the whole block 90 degrees clockwise
- the first line becomes the leftmost column (bottom), last line becomes rightmost column (top)
- **Goal: output column by column, each column read from last line to first line**

## 3. Thinking Logic and Solution Strategy

### Final Strategy

- store all lines, pad to the same length with spaces
- for each column `j` (0 to maxLen-1):
  - read from bottom to top: `lines[n-1][j]`, `lines[n-2][j]`, ..., `lines[0][j]`
  - this gives one output row
- trim trailing spaces on each output row
- why it works: 90° clockwise rotation maps column j (bottom-to-top) to row j (left-to-right)
- edge cases: lines of different lengths -> pad with spaces; trailing spaces in output -> trim

## 4. Pseudocode

```text
START
1. read all lines, find maxLen
2. pad each line to maxLen with spaces
3. for j = 0..maxLen-1:
4. row = ""
5. for i = n-1 down to 0: row += lines[i][j]
6. trim trailing spaces from row
7. print row
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/490-fail.cpp](./src/490-fail.cpp))

**Why it failed:**

- read the lines and found maxLen, but never rotated or printed

### Correct Code

(See [src/490-correct.cpp](./src/490-correct.cpp))

**Why it works:**

- padding ensures all lines are the same length -> safe to access any `lines[i][j]`
- reading bottom-to-top per column = 90° clockwise rotation
- trimming trailing spaces gives clean output

## 6. Difference and Reflection

### Reflection

- what I learned: "rotate text 90°" = read columns instead of rows, reverse the order
- pad shorter lines with spaces first so indexing doesn't go out of bounds
- trim trailing spaces in each output row

* next time: 2D text rotation -> think of it as transposing + reversing one axis
