# UVa 10008 - What's Cryptanalysis?

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10008
- **Problem Title:** What's Cryptanalysis?
- **Problem Link:** https://onlinejudge.org/external/100/10008.pdf
- **Source Code (Fail):** [src/10008-fail.cpp](./src/10008-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10008-correct.cpp](./src/10008-correct.cpp)

## 2. Problem Statement in My Own Words

- read `N` lines of text
- count how many times each letter `A`-`Z` appears
- upper and lower case = same letter (output as uppercase)
- ignore anything that is not a letter
- Output: one line per letter -> `LETTER COUNT`
- **Goal: list letters by count, most first; ties by alphabet; skip letters with count 0**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: a `map<char,int>` to count letters
- must read whole lines (text has spaces) -> `getline`, not `cin >>`
- after `cin >> n`, do `cin.ignore()` so the first `getline` does not grab the leftover newline

### Final Strategy

- use a size-26 array, `count[c - 'A']`, for `A`..`Z`
- each line: for each char, if it is a letter -> `count[toupper(c) - 'A']++`
- collect `(count, letter)` pairs where count != 0
- sort by count desc, then letter asc
- print `letter count`
- why it works: the array indexes letters directly; one sort handles both rules at once
- edge cases:
  - empty lines, or lines with only symbols / digits -> just skip
  - mixed case -> `toupper` first
  - letters that never appear -> not printed

## 4. Pseudocode

```text
START
1. read n, then ignore the rest of that line
2. count[26] = 0
3. repeat n times:
4. getline s
5. for each char c in s:
6. if c is a letter: count[upper(c) - 'A'] += 1
7. build list of (count, letter) where count != 0
8. sort by count desc, then letter asc
9. print each "letter count"
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    int n = 0; //CaseNum
    cin >> n;
    cin.ignore();
    string text;
    map<char, int> count;




    return 0;
}
```

**Why it failed:**

- only set up the variables (`n`, `text`, `map count`) and read `n` + `cin.ignore()`
- never read the lines, never counted, never sorted, never printed -> no output
- the `map` was declared but never used; the whole core was missing

### Correct Code

```cpp
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();

    int count[26] = {0};

    while(n--)
    {
        string s;
        getline(cin, s);

        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i]))
                count[toupper(s[i]) - 'A']++;
        }
    }

    vector<pair<int,char>> res;
    for(int j = 0; j < 26; j++)
        if(count[j] != 0)
            res.push_back({count[j], (char)('A' + j)});

    sort(res.begin(), res.end(), [](auto& a, auto& b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });

    for(auto& p : res)
        cout << p.second << " " << p.first << endl;

    return 0;
}
```

**Why it works:**

- `getline` reads each full line (keeps spaces)
- `isalpha` filter + `toupper` -> count case-insensitively into `count[26]`
- pushes only letters with count != 0
- sort: count desc, tie -> letter asc
- prints in the required `letter count` format

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty -> no counting / sorting | `count[26]` + letter filter + sort |
| Edge Cases | none handled | skips non-letters, handles case, skips 0-count |
| Output Handling | prints nothing | prints `letter count`, sorted |
| Other | declared a `map`, stopped at setup | array + `getline` + `isalpha` / `toupper` |

### Reflection

- my mistake: stopped after defining variables and reading `n`; never wrote the core loop or output
- what I learned: read full lines with `getline` (text has spaces); use `cin.ignore()` after `cin >> n`; a 26-size array is simpler than a `map` for fixed `A`-`Z`

* next time: write counting + sorting + output before testing; pick the data structure that fits the job (array for `A`-`Z`)
