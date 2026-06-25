# LeetCode 394 - Decode String

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 394
- **Problem Title:** Decode String
- **Problem Link:** https://leetcode.com/problems/decode-string/description/
- **Source Code (Fail):** [src/lc394-fail.cpp](./src/lc394-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc394-correct.cpp](./src/lc394-correct.cpp)

## 2. Problem Statement in My Own Words

- encoded string: `k[encoded_string]` means repeat `encoded_string` k times
- can be nested: `3[a2[c]]` -> `accaccacc`
- Input: encoded string with digits, letters, `[`, `]`
- **Goal: decode the string, handling nested brackets**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- nesting means I need to "pause" the outer string while I decode the inner one -> stack
- two stacks: one for the strings built so far, one for the repeat counts

### Final Strategy

- `strSt` (string stack), `numSt` (number stack), `cur` (current string), `num` (current number)
- digit -> build `num` (multi-digit: `num = num * 10 + digit`)
- `[` -> push `cur` and `num` onto stacks, reset both
- `]` -> pop `tmp` and `k`; `cur = tmp + cur repeated k times`
- letter -> append to `cur`
- why it works: each `[` saves the outer context; each `]` merges the inner result back
- edge cases: multi-digit numbers like `12[a]`, nested like `3[a2[c]]`, letters outside brackets

## 4. Pseudocode

```text
START
1. strSt = [], numSt = [], cur = "", num = 0
2. for each char c:
3. if digit: num = num * 10 + (c - '0')
4. if '[': push cur and num; reset both
5. if ']': pop tmp and k; cur = tmp + cur * k
6. else: cur += c
7. return cur
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<string> strSt;
        stack<int> numSt;
        string cur = "";
        int num = 0;



        return cur;
    }
};
```

**Why it failed:**

- set up the stacks but never processed any characters

### Correct Code

```cpp
class Solution {
public:
    string decodeString(string s) {
        stack<string> strSt;
        stack<int> numSt;
        string cur = "";
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                strSt.push(cur);
                numSt.push(num);
                cur = "";
                num = 0;
            } else if (c == ']') {
                string tmp = strSt.top(); strSt.pop();
                int k = numSt.top(); numSt.pop();
                for (int i = 0; i < k; i++) tmp += cur;
                cur = tmp;
            } else {
                cur += c;
            }
        }
        return cur;
    }
};
```

**Why it works:**

- `[` saves the outer context (string + count) onto stacks -> like opening a new scope
- `]` merges inner result back by repeating `cur` k times and prepending the saved string
- handles nesting naturally because each level gets its own push/pop pair

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | two stacks: save context at `[`, restore at `]` |
| Edge Cases | none | multi-digit numbers, nesting, letters outside brackets |
| Output Handling | returns empty | returns fully decoded string |
| Other | only setup | O(output length) |

### Reflection

- what I learned: nested bracket problems -> use a stack to save/restore context at each level
- the two-stack trick (one for strings, one for counts) is the standard pattern

* next time: "nested encoding" or "recursive structure in a flat string" -> two stacks
