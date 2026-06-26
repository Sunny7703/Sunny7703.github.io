# UVa 11349 - Symmetric Matrix

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11349
- **Problem Title:** Symmetric Matrix
- **Problem Link:** https://onlinejudge.org/external/113/11349.pdf
- **Source Code (Fail):** [src/11349-fail.cpp](./src/11349-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11349-correct.cpp](./src/11349-correct.cpp)

## 2. Problem Statement in My Own Words

- `T` cases; each: `N = n`, then an `n x n` matrix
- check: `M[i][j] == M[j][i]` for all i, j AND all elements >= 0
- **Goal: verify symmetry + non-negative**
  - values can be very large -> use `long long`

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- check if a matrix is symmetric AND all elements are non-negative

### Final Strategy

- read matrix into `long long m[n][n]`
- check every pair: if `m[i][j] != m[j][i]` or `m[i][j] < 0` -> not symmetric
- input format: `N = n` (use `scanf(" N = %d", &n)` to parse)
- edge cases: negative numbers, large values (> 2^31)

## 4. Pseudocode

```text
START
1. for each case:
2. read N = n, read n*n values
3. for i, j: if m[i][j] < 0 or m[i][j] != m[j][i]: not symmetric
4. print result
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/11349-fail.cpp](./src/11349-fail.cpp))

**Why it failed:**

- read the matrix but never checked symmetry or non-negative

### Correct Code

(See [src/11349-correct.cpp](./src/11349-correct.cpp))

**Why it works:**

- checks both conditions (symmetric + non-negative) in one pass
- `long long` handles large values
- `scanf(" N = %d")` correctly parses the input format

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | check m[i][j] == m[j][i] and >= 0 for all pairs |

### Reflection

- what I learned: read the problem carefully -> "symmetric" here also requires non-negative (easy to miss)
- `scanf` with format string is useful for parsing tricky input like `N = 3`

* next time: check ALL conditions in the definition, not just the obvious one
