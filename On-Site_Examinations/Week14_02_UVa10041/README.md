# UVa 10041 - Vito's Family

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10041
- **Problem Title:** Vito's Family
- **Problem Link:** https://onlinejudge.org/external/100/10041.pdf
- **Source Code (Fail):** [src/10041-fail.cpp](./src/10041-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10041-correct.cpp](./src/10041-correct.cpp)

## 2. Problem Statement in My Own Words

- `T` cases; each: `R` relatives + their street numbers
- Vito picks a street to live on
- Output: minimum total distance from Vito to all relatives
- **Goal: minimize sum of |relative[i] - vito|**
  - the optimal spot is the MEDIAN of the relative positions

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- find the street number that minimizes total walking distance for all relatives

### Final Strategy

- sort the street numbers
- pick the median (middle value)
- sum up |each - median|
- why it works: the median minimizes the sum of absolute deviations (proven math fact)
- for even count: any value between the two middles works; integer average is fine

## 4. Pseudocode

```text
START
1. for each case:
2. read R and the R street numbers
3. sort them
4. median = middle value (or avg of two middles)
5. total = sum of |each - median|
6. print total
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/10041-fail.cpp](./src/10041-fail.cpp))

**Why it failed:**

- only read the street numbers and sorted them
- never computed median or distances

### Correct Code

(See [src/10041-correct.cpp](./src/10041-correct.cpp))

**Why it works:**

- sorts, picks median, sums absolute differences
- median minimizes the total distance (math fact)
- works for both odd and even counts

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | sort + median + sum |x - median| |

### Reflection

- what I learned: "minimize sum of absolute differences" = use the MEDIAN
- mean minimizes sum of SQUARES; median minimizes sum of ABSOLUTES

* next time: see "minimize total distance" on a 1D line -> median
