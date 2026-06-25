# UVa 673 - Parentheses Balance

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 673
- **Problem Title:** Parentheses Balance
- **Problem Link:** https://onlinejudge.org/external/6/673.pdf
- **Source Code (Fail):** [src/673-fail.cpp](./src/673-fail.cpp)
- **Source Code (Correct/Accepted):** [src/673-correct.cpp](./src/673-correct.cpp)

## 2. Problem Statement in My Own Words

- given a string with `(`, `)`, `[`, `]` only
- check if it is PROPERLY nested:
  - every open bracket has a matching close of the SAME type
  - no crossing: `([)]` is WRONG, `([])` is OK
  - nesting is OK: `([()])` is OK
- empty string = balanced -> "Yes"
- Input: `T`, then `T` lines (can be empty)
- Output: `Yes` or `No` per line
- **Goal: check both matching AND nesting order -> needs a stack**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first (wrong) idea: use nested loops to find matching brackets and mark them -> fails on many cases
- second (also wrong) idea: just count brackets, if total is 0 then balanced -> misses crossing like `([)]`
- key: the ORDER matters, not just the COUNT -> a stack tracks what was opened and in what order

### Final Strategy

- use a stack of chars:
  - open bracket `(` or `[` -> push it
  - close bracket `)` -> check if top is `(`, if yes pop, else fail
  - close bracket `]` -> check if top is `[`, if yes pop, else fail
  - stack empty when we see a close -> fail (nothing to match)
- after the loop: if stack is empty AND no failures -> "Yes"
- important: use `getline(cin, s)` (not `cin >> s`), because the input can have EMPTY lines
- `cin.ignore()` after `cin >> t` to eat the newline before the first `getline`
- why it works:
  - the stack enforces LIFO -> the most recent open must be closed first
  - `([)]` fails: push `(`, push `[`, see `)` but top is `[` -> mismatch -> No
  - `([])` works: push `(`, push `[`, see `]` matches `[` pop, see `)` matches `(` pop -> empty -> Yes
- edge cases:
  - empty line -> stack stays empty, no failures -> "Yes"
  - only close brackets -> stack is empty when we try to match -> "No"
  - only open brackets -> stack not empty at the end -> "No"

## 4. Pseudocode

```text
START
1. read t, then cin.ignore()
2. repeat t times:
3. getline s
4. stack st, ok = true
5. for each char c in s:
6. if c is '(' or '[': push c
7. if c is ')': if top is '(' -> pop, else ok = false
8. if c is ']': if top is '[' -> pop, else ok = false
9. if ok AND st is empty: "Yes"; else "No"
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        bool balance = true;
        for(int i = 0; i < (int)s.length() - 1; i++)
        {
            for(int j = i; j < (int)s.length() - 2; j++)
            {
                if(s[i] == '(')
                {
                    balance = false;
                    if(s[j] == ')')
                    {
                        balance = true;
                        s[j] = '0';
                        break;
                    }
                }
                else if(s[i] == '[')
                {
                    balance = false;
                    if(s[j] == ']')
                    {
                        balance = true;
                        s[j] = '0';
                        break;
                    }
                }
            }
        }

        if(balance)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
```

**Why it failed:**

- tries to match `s[i]` with any `s[j]` to the right, then marks `s[j]` as `'0'`
- this does NOT check nesting order: `([])` fails because `(` at i=0 finds `)` at j=3, but the inner `[]` at 1-2 has already been skipped by the outer loop
- actually `([])` gives "No" even though it's valid -> wrong
- also uses `cin >> s` -> skips empty lines (empty line should be "Yes")
- the loop bounds `s.length() - 1` and `s.length() - 2` cut off the last characters -> misses matches at the end

### Correct Code

```cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(); // eat the newline after the number

    while (t--)
    {
        string s;
        getline(cin, s); // getline handles empty lines too

        stack<char> st;
        bool ok = true;

        for (int i = 0; i < (int)s.length() && ok; i++)
        {
            if (s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.empty() || st.top() != '(') ok = false;
                else st.pop();
            }
            else if (s[i] == ']')
            {
                if (st.empty() || st.top() != '[') ok = false;
                else st.pop();
            }
        }

        if (ok && st.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
```

**Why it works:**

- stack enforces LIFO -> the most recently opened bracket must close first
- `([)]`: push `(`, push `[`, see `)` but top is `[` -> mismatch -> No
- `([])`: push `(`, push `[`, see `]` matches `[` pop, see `)` matches `(` pop -> empty -> Yes
- `getline` reads empty lines too -> empty string = empty stack = "Yes"
- `cin.ignore()` after `cin >> t` prevents the first `getline` from grabbing a stale newline
- checks `st.empty()` before `st.top()` to avoid undefined behaviour on empty stack

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | nested loops + mark as '0' (no nesting awareness) | stack-based (LIFO enforces nesting) |
| Edge Cases | `cin >> s` skips empty lines; loop bounds cut off end | `getline` handles empty lines; full scan |
| Output Handling | wrong answers on valid nested strings like `([])` | correct for all cases |
| Other | O(n^2) and still wrong | O(n) and correct |

### About my earlier "correct" version (single counter)

- that version used `num++` for `(`/`[` and `num--` for `)`/`]`, then checked `num == 0`
- problem: it only counts, it does NOT check nesting ORDER
- `([)]` has count 0 -> it says "Yes" -> **wrong**
- also uses `cin >> s` -> skips empty lines
- it's slightly better than the nested-loop version (at least `([])` passes), but still fails on crossing brackets

### Reflection

- my mistake: tried to match brackets with brute-force scanning (wrong) and then with a single counter (also wrong) -> neither tracks nesting order
- what I learned:
  - "bracket matching with nesting" = use a STACK; there is no shortcut
  - the stack gives you LIFO: the last bracket opened must be the first one closed -> exactly what "properly nested" means
  - `cin >> s` cannot handle empty lines -> use `getline` + `cin.ignore()`
  - `st.empty()` check before `st.top()` prevents undefined behaviour

* next time: when the problem says "properly nested" or "balanced with multiple bracket types", reach for a stack immediately; counting alone can never track the ORDER of nesting
