# UVa 10252 - Common Permutation

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10252
- **Problem Title:** Common Permutation
- **Problem Link:** https://onlinejudge.org/external/102/10252.pdf
- **Source Code (Fail):** [src/10252-fail.cpp](./src/10252-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10252-correct.cpp](./src/10252-correct.cpp)

## 2. Problem Statement in My Own Words

- two strings `a` and `b` per case (read until EOF)
- find the longest string X where X is a common subsequence of both (by rearranging)
- Output: X in sorted (alphabetical) order
- **Goal: for each letter, take min(count in a, count in b) copies, output sorted**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- find the longest string X such that some permutation of X is a subsequence of BOTH a and b

### Final Strategy

- count each letter's frequency in both strings: `ca[26]`, `cb[26]`
- for each letter a..z: output `min(ca[i], cb[i])` copies
- why it works: a letter can appear in X at most as many times as it appears in BOTH strings
- must use `getline` (not `cin >>`) because the input has one string per line
- edge cases: no common letters -> empty line; one string is empty

## 4. Pseudocode

```text
START
1. while getline a, getline b:
2. ca[26] = count letters in a
3. cb[26] = count letters in b
4. for i = 0..25:
5. print char('a'+i) repeated min(ca[i], cb[i]) times
6. print newline
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/10252-fail.cpp](./src/10252-fail.cpp))

**Why it failed:**

- used `cin >> a >> b` instead of `getline` -> breaks on multi-word input
- nested O(n*m) loop checking `a[i] == b[j]` -> counts duplicates wrong (finds ALL pairs, not min)
- loop bounds `<= length()` -> reads past the end of the string (out of bounds)
- only prints each letter ONCE regardless of how many times it should appear

### Correct Code

(See [src/10252-correct.cpp](./src/10252-correct.cpp))

**Why it works:**

- `getline` reads full lines
- two count arrays `ca[26]`, `cb[26]` -> O(n+m)
- `min(ca[i], cb[i])` gives the exact number of shared copies
- output in order a..z -> automatically sorted

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | O(n*m) with wrong counts | O(n+m) with count arrays + min |

### Reflection

- my mistake: tried to match characters with nested loops; should just count and take min
- what I learned: "common permutation" = per-letter min of two frequency counts
- `getline` vs `cin >>` matters when input is line-based

* next time: for letter frequency problems, use a 26-size array (faster and simpler than map)
