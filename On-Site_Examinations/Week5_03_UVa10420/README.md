# UVa 10420 - List of Conquests

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10420
- **Problem Title:** List of Conquests
- **Problem Link:** https://onlinejudge.org/external/104/10420.pdf
- **Source Code (Fail):** [src/10420-fail.cpp](./src/10420-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10420-correct.cpp](./src/10420-correct.cpp)

## 2. Problem Statement in My Own Words

- read `T`, then `T` lines
- each line: `country name` where `country` is one word, `name` can be one OR more words
- count how many girls came from each country
- Output: `country count`, one per line, sorted by country name (a-z)
- **Goal: count girls per country, then print them in alphabetical order**
  - only the country matters; ignore the names

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: `map<string,int>` -> auto sorted by key (country)
- tricky: the line has the country first, then the name with spaces -> mix of `cin >>` and `getline`

### Final Strategy

- read `T`
- repeat `T` times:
  - `cin >> country` -> reads the first word
  - `cin.ignore()` -> skip the space (and the leftover newline) before reading the rest
  - `getline(cin, name)` -> eat the rest of the line (we don't actually need the name)
  - bump the count for that country
- print `country count` for every entry in the map (already sorted)
- why it works:
  - `cin >>` stops at whitespace -> gets just the country
  - `cin.ignore()` clears the space/newline so `getline` reads only what's left
  - `map` sorts keys for free
- edge cases:
  - first `cin >> t` leaves a newline -> need `cin.ignore()` BEFORE the first `getline`, not after
  - name has spaces -> can't use `cin >> name`, must use `getline`
  - same country can appear many times -> `m[country]++` is fine

## 4. Pseudocode

```text
START
1. read t
2. repeat t times:
3. cin >> country
4. cin.ignore() // skip the rest of the line for getline
5. getline name // not used, just consumes the line
6. m[country] += 1
7. for each (country, count) in m (sorted by key):
8. print "country count"
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    map<string, int> m;

    while(t--)
    {
        string c, n;
        cin >> c;
        getline(cin, n);
        cin.ignore();
        m[c]++;
    }

    cout << << endl;
}
```

**Why it failed:**

- `cout << << endl;` is missing an expression in the middle -> compile error (CE), code never runs
- order is wrong: `getline` first, `cin.ignore()` after
  - after `cin >> c` there is still a leftover `\n` / space on the line
  - `getline(cin, n)` reads that leftover right away -> `n` is empty (or wrong), and the real name leaks into the next loop's `cin >> c`
  - the `cin.ignore()` after `getline` runs at the wrong time
- no output loop -> even if it compiled, it would never print the country counts

### Correct Code

```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    map<string, int> m;
    string save[t];
    int i = 0;

    while(t--)
    {
        string country;
        cin >> country;
        save[i] = country;
        i++;
        cin.ignore();
        string name;
        getline(cin, name);
    }
    for (const string& s : save) {
        m[s]++;
    }

    for(auto p : m)
    {
        cout << p.first << " " << p.second << endl;
    }
}
```

**Why it works:**

- `cin >> country` reads the first word (no spaces)
- `cin.ignore()` skips the leftover space/newline before `getline`
- `getline(cin, name)` eats the rest of the line (name not used, just discarded so the next round reads cleanly)
- saves each country, then counts in `m`; `map` auto-sorts by key
- final loop prints `country count` in alphabetical order

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | counts inside the loop but never prints | reads cleanly, counts after, prints sorted |
| Edge Cases | mixes `cin >>` and `getline` in the WRONG order | `cin.ignore()` BEFORE `getline` |
| Output Handling | `cout << << endl;` -> compile error | loops over the map and prints `country count` |
| Other | one line per case treated as 2 separate reads with no clean-up | save -> count -> sort -> print |

### Reflection

- my mistake:
  - typed `cout << << endl;` without filling in what to print -> CE
  - put `cin.ignore()` AFTER `getline` -> the leftover newline was never skipped
  - forgot to add an output loop for the map
- what I learned:
  - mixing `cin >>` with `getline` -> always do `cin.ignore()` IN BETWEEN (right after `cin >>`, before `getline`)
  - `map<string,int>` already iterates in key order -> no extra sort needed
  - compile first, then test -> a CE means zero info about logic

* next time: read what I just typed before saving; write the output loop right after the input loop so I don't forget it
