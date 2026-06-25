# UVa 10062 - Tell me the frequencies!

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10062
- **Problem Title:** Tell me the frequencies!
- **Problem Link:** https://onlinejudge.org/external/100/10062.pdf
- **Source Code (Fail):** [src/10062-fail.cpp](./src/10062-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10062-correct.cpp](./src/10062-correct.cpp)

## 2. Problem Statement in My Own Words

- many lines of text (read until EOF), each line up to 1000 chars
- chars are printable ASCII only (32..126), spaces count too
- ignore `\n` / `\r`
- Output per line: `ASCII count`
- **Goal: list each char's ASCII + count, sorted by count low to high, ties by ASCII high to low**
  - print a BLANK line BETWEEN cases (not after the last one)

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: `count[128]`, do `count[(int)c]++` for each char
- text has spaces -> must use `getline`, not `cin >>`
- watch the sort order: count ASCENDING, but ASCII DESCENDING on tie

### Final Strategy

- per line:
  - clear `count[128]`
  - for each char `c` in the line: `count[(int)c]++`
  - collect `(ascii, count)` for `ascii` in 32..126 where count > 0
  - sort: count asc; tie -> ascii desc
  - print each `ascii count`
- output: print a blank line BEFORE every case except the first
- why it works:
  - `(int)c` is just the char's ASCII value -> direct index into `count[]`
  - one custom sort handles both rules
  - the "first" flag avoids the trailing blank line
- edge cases:
  - empty line -> nothing to print, but still counts as a case (still need the blank separator next time)
  - `\r` from Windows endings -> just count it (problem says ignore, but `getline` already strips `\n`; if needed, can pop a trailing `\r`)
  - ties on count -> ASCII DESC (higher ASCII first), not the usual asc

## 4. Pseudocode

```text
START
1. first = true
2. while getline(line):
3. count[128] = 0
4. for c in line: count[(int)c] += 1
5. res = [(a, count[a]) for a in 32..126 if count[a] > 0]
6. sort res by count asc, tie by ascii desc
7. if not first: print blank line
8. first = false
9. for (a, c) in res: print "a c"
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string line;
    bool first = true;

    while (getline(cin, line))
    {
        int count[128] = {0};



    }
    return 0;
}
```

**Why it failed:**

- only set up the read loop and the `count[128]` array
- never counted, never sorted, never printed -> no output

### Correct Code

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string line;
    bool first = true;

    while (getline(cin, line))
    {
        int count[128] = {0};

        for (int i = 0; i < (int)line.length(); i++)
        {
            int ascii = (int)line[i]; // char -> ASCII value
            count[ascii]++;
        }

        vector<pair<int,int>> res; // (ascii, freq)
        for (int a = 32; a <= 126; a++)
            if (count[a] > 0)
                res.push_back({a, count[a]});

        sort(res.begin(), res.end(), [](auto& x, auto& y){
            if (x.second != y.second) return x.second < y.second; // freq asc
            return x.first > y.first;                              // tie: ascii desc
        });

        if (!first) cout << endl;   // blank line BETWEEN cases (not after the last)
        first = false;

        for (auto& p : res)
            cout << p.first << " " << p.second << endl;
    }
    return 0;
}
```

**Why it works:**

- `(int)line[i]` -> the ASCII value of that char, used directly as the index
- `count[128]` resets every line -> each line is its own case
- collects only chars that appeared (`count > 0`)
- custom sort: count asc, ASCII desc on tie -> matches the spec
- `first` flag prints a blank line ONLY between cases, not after the last

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> no counting / sorting | count via `(int)c`, sort by count asc + ASCII desc |
| Edge Cases | none handled | resets per line, skips count==0, handles tie order |
| Output Handling | prints nothing | `ASCII count` per line, blank line BETWEEN cases only |
| Other | declared `count[128]`, did nothing with it | indexes `count[ascii]` directly with the char's value |

### Reflection

- my mistake: stopped at the setup, never wrote the core loop or output
- what I learned:
  - `(int)c` IS the ASCII value -> use the char itself as the array index, no need to subtract anything
  - text has spaces -> `getline`, not `cin >>`
  - read the sort rule carefully: count ASC but ASCII DESC on tie
  - blank line goes BETWEEN cases; one extra after the last = WA

* next time: write counting + sorting + output first; double-check the "between cases" vs "after each case" rule, they're not the same
