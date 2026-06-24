# UVa 12503 - Robot Instructions

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 12503
- **Problem Title:** Robot Instructions
- **Problem Link:** https://onlinejudge.org/external/125/12503.pdf
- **Source Code (Fail):** [src/12503-fail.cpp](./src/12503-fail.cpp)
- **Source Code (Correct/Accepted):** [src/12503-correct.cpp](./src/12503-correct.cpp)

## 2. Problem Statement in My Own Words

- robot starts at the origin (position 0) on a line
- 3 kinds of instructions:
  - `LEFT` -> move -1
  - `RIGHT` -> move +1
  - `SAME AS i` -> do the same move as instruction number `i`
- Input: `T` test cases; each = `n`, then `n` instruction lines
- Output: final position after each test case (reset to 0 between cases)
- **Goal: find each instruction's move, then add them up for the final position**
  - must remember every past move, because `SAME AS i` looks one up

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: keep a running position, add/subtract per instruction
- problem: `SAME AS i` needs the move of an OLD instruction -> must store every move

### Final Strategy

- store each move in `move[i]` (+1 or -1)
- `LEFT` -> -1, `RIGHT` -> +1, `SAME AS i` -> copy `move[i]`
- add every move to `pos`
- why it works: `SAME AS i` always points to an earlier `i` that is already known -> can look it up safely
- edge cases:
  - `SAME AS i` can chain (i is itself a SAME) -> still fine, `move[i]` already holds the real value
  - reset `pos` to 0 each test case
  - instructions are 1-based (index starts at 1)

## 4. Pseudocode

```text
START
1. read t
2. repeat t times:
3. read n, pos = 0
4. for i = 1..n:
5. read cmd
6. if cmd == LEFT:  move[i] = -1
7. if cmd == RIGHT: move[i] = +1
8. if cmd == SAME:  read "AS" and k, move[i] = move[k]
9. pos += move[i]
10. print pos
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> move(n + 1); // move[i] = +1 or -1 for instruction i
        int pos = 0;

        for (int i = 1; i <= n; i++)
        {
            string cmd;
            cin >> cmd;

        }

    }
    return 0;
}
```

**Why it failed:**

- only set up the variables and read input
- never handled `LEFT` / `RIGHT` / `SAME AS` -> `move[i]` and `pos` never change
- never printed anything -> no answer
- also `cin >> cmd` reads only `SAME` on a SAME line -> `AS` and the number are left unread (the missing part)

### Correct Code

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> move(n + 1); // move[i] = +1 or -1 for instruction i
        int pos = 0;

        for (int i = 1; i <= n; i++)
        {
            string cmd;
            cin >> cmd;

            if (cmd == "LEFT")
                move[i] = -1;
            else if (cmd == "RIGHT")
                move[i] = 1;
            else // SAME AS k
            {
                string as;
                int k;
                cin >> as >> k; // read "AS" and the index k
                move[i] = move[k];
            }

            pos += move[i];
        }

        cout << pos << endl;
    }
    return 0;
}
```

**Why it works:**

- maps each command to a move: `LEFT` -> -1, `RIGHT` -> +1, `SAME AS k` -> `move[k]`
- stores every move, so a later `SAME AS k` can look it back up
- reads all 3 tokens on a SAME line (`SAME`, `AS`, `k`)
- adds each move to `pos`, prints `pos` per test case

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> no move handling | maps each command to a move, sums them |
| Edge Cases | none handled | handles `SAME AS` chains, resets `pos` per case |
| Output Handling | prints nothing | prints final `pos` per test case |
| Other | reads only `SAME` on a SAME line | reads `AS` and the index too |

### Reflection

- my mistake: stopped at the input setup, never wrote the logic or output
- what I learned: for `SAME AS i`, store every move so I can look it back up; a SAME line has 3 tokens (`SAME` / `AS` / number), so I must read all three

* next time: finish the core logic and output before testing; plan what data I need to store first
