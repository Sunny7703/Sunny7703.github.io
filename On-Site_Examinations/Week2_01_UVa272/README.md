# UVa 272 - TEX Quotes

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 272
- **Problem Title:** TEX Quotes
- **Problem Link:** https://onlinejudge.org/external/2/272.pdf
- **Source Code (Fail):** [src/272-fail.cpp](./src/272-fail.cpp)
- **Source Code (Correct/Accepted):** [src/272-correct.cpp](./src/272-correct.cpp)

## 2. Problem Statement in My Own Words

- replace `"` with LaTeX-style quotes
- odd occurrence (opening) -> `` `` ``
- even occurrence (closing) -> `''`
- alternate: first `"` is opening, second is closing, third opening, ...
- everything else stays the same (including newlines)
- **Goal: toggle between `` `` `` and `''` each time a `"` is seen**

## 3. Thinking Logic and Solution Strategy

### Final Strategy

- a `bool open = true` flag, toggles each time we see `"`
- read char by char with `cin.get(c)` (keeps whitespace and newlines)
- if `"`: print `` `` `` or `''` based on flag, then flip
- else: print the char as-is
- edge cases: multiple quotes on one line, quotes across lines

## 4. Pseudocode

```text
START
1. open = true
2. while cin.get(c):
3. if c == '"':
4. if open: print "``"; else: print "''"
5. open = !open
6. else: print c
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/272-fail.cpp](./src/272-fail.cpp))

**Why it failed:**

- read each char but never checked for `"` or printed replacements

### Correct Code

(See [src/272-correct.cpp](./src/272-correct.cpp))

**Why it works:**

- `cin.get(c)` reads every char including whitespace
- bool flag alternates between opening and closing quotes
- everything that isn't `"` passes through unchanged

## 6. Difference and Reflection

### Reflection

- what I learned: `cin.get(c)` reads ALL chars (unlike `cin >> c` which skips whitespace)
- a simple boolean toggle handles the alternation perfectly

* next time: "alternating replacement" -> use a bool flag and flip it
