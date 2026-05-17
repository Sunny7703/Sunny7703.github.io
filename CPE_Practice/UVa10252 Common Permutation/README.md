# [UVa] [10252] - [Common Permutation]

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10252
- **Problem Title:** Common Permutation
- **Problem Link:** https://onlinejudge.org/external/102/10252.pdf
- **Source Code (Fail):** [src/your-file-name.cpp](./src/your-file-name.cpp)
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/your-file-name.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- What is the input?
- What is the expected output?
- What are the main rules or constraints?
- What is the core task you must solve?

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- What was your first idea?
- What difficulty did you notice at the beginning?

### Final Strategy

- What method did you finally use?
- Why does this method work?
- What edge cases did you consider?

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. 
2. 
3. 
4. 
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>
#include <map>
using namespace std;

int main()
{
    string a;
    string b;
    
    while(cin >> a >> b)
    {
        map<char, int> m;
        
        for(int i = 0; i <= a.length(); i++)
        {
            for(int j = 0; j <= b.length(); j++)
            {
                if(a[i] == b[j])
                    m[a[i]]++;
            }
        }
        
        for(auto &p : m)
        {
            cout << p.first;
        }

        cout << endl;
    }
```

**Why it failed:**

- a[a.length()] = '\0' (null terminator), so the boundary of for loops should be < a.length() or b.length().
- Repeated characters will not be printed out.
- * Maps are more useful when the key range is large or unknown.** 

### Correct Code

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string a, b;
    while(getline(cin, a) && getline(cin, b))
    {
        int ca[26] = {}, cb[26] = {};
        
        for(char c : a)
            ca[c - 'a']++; //char -> int
        for(char c : b)
            cb[c - 'a']++;
        
        for(int i = 0; i < 26; i++)
        {
            int times = min(ca[i], cb[i]); //min 兩邊都有出現的最小就是重複的字母數量
            for(int j = 0; j < times; j++)
                cout << (char)('a' + i); //int -> char
        }
        cout << endl;
    }
}

```

**Why it works:**

- The input "might" contains space, so changing cin to getline will be more accurate.
- 



## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic |  |  |
| Edge Cases |  |  |
| Output Handling |  |  |
| Other |  |  |

### Reflection

- What mistake did you make?
- What did you learn from debugging this problem?
If you solve a similar problem again, what will you do better?
