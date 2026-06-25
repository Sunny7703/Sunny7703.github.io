# LeetCode 20 - Valid Parentheses

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 20
- **Problem Title:** Valid Parentheses
- **Problem Link:** https://leetcode.com/problems/valid-parentheses/description/
- **Source Code (Fail):** [src/lc20-fail.cpp](./src/lc20-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc20-correct.cpp](./src/lc20-correct.cpp)

## 2. Problem Statement in My Own Words

- string with `()`, `{}`, `[]` only
- check if properly nested: matching types, correct order
- **Goal: use a stack to enforce LIFO nesting**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- counting alone won't work -> `([)]` has equal counts but is invalid
- stack tracks WHAT was opened and in WHAT order

### Final Strategy

- open bracket -> push
- close bracket -> check top matches, then pop; mismatch or empty -> false
- end: stack must be empty
- edge cases: empty string (true), only opens (false), only closes (false)

## 4. Pseudocode

```text
START
1. for each char c in s:
2. if c is open: push c
3. if c is close: if stack empty or top doesn't match: return false; else pop
4. return stack is empty
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;



        return st.empty();
    }
};
```

**Why it failed:**

- never pushed or popped anything -> stack stays empty -> always returns true

### Correct Code

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if (st.empty()) return false;
                char top = st.top(); st.pop();
                if (c == ')' && top != '(') return false;
                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
            }
        }
        return st.empty();
    }
};
```

**Why it works:**

- stack enforces LIFO -> last opened must close first
- checks empty before top -> no undefined behaviour
- final `st.empty()` catches unclosed brackets

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | stack push/pop with type matching |
| Edge Cases | always true | handles mismatches, empty stack, unclosed |
| Output Handling | wrong for most inputs | correct for all |
| Other | only setup | O(n) time, O(n) space |

### Reflection

- what I learned: bracket matching with multiple types = stack; same idea as UVa 673
- `st.empty()` check before `st.top()` prevents crashes

* next time: see "valid parentheses" or "balanced brackets" -> reach for stack immediately
