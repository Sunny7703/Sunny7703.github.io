# [UVa] [100] - [3n+1]


## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 100
- **Problem Title:** The 3n + 1 problem
- **Problem Link:** https://onlinejudge.org/external/1/100.pdf
- **Source Code (Original code):** [src/your-file-name.cpp](./src/your-file-name.cpp)
- **Source Code (Impoved code):** [src/your-file-name.cpp](./src/your-file-name.cpp)

## 2. Problem Statement in My Own Words

According to the algorithm, while n != 1, the cycle count will be added once by running one step. From the range i to j, I need to output the maximum cycle count. 

- What is the input?
  A: i and j
- What is the expected output?
  A: Maximum cycle count

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

## 5. Original Code vs Improved Code


### Original Code

```cpp
#include <iostream>
using namespace std;

int algorithm(int n)
{
    int count = 1;
    while(n != 1)
    {
        if(n % 2 == 1)
            n = 3 * n + 1;
        else
            n = n / 2;
        count++;
    }
    
    return count;
}
int main()
{
    int i = 0, j = 0;
    
    while(cin >> i >> j)
    {
        cout << i << " " << j << " ";
        
        if(j < i)
            swap(i,j);
        
        int max = 0;
        for(int k = i; k <= j; k++)
        {
            if(algorithm(k) > max)
                max = algorithm(k);
        }
        
        cout << max << endl;
    }
    return 0;
}

```

**How can I improves:**
- Calling Algorithm twice
  ```cpp
   for(int k = i; k <= j; k++)
        {
            int len = algorithm(k);
            if(len > max)
                max = len;
        }
  ```
- The numbers within the sequence might overflow
  ```cpp
  int cycleLength(long n)
  ```
  
### Improved Code

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int CACHE = 1000000;   // 涵蓋大部分中間峰值
int memo[CACHE];             // 全域陣列，自動初始化為 0

int cycleLength(long n)
{
    if (n == 1) return 1;
    if (n < CACHE && memo[n] != 0)   // 0 代表「還沒算過」
        return memo[n];

    int result = (n % 2 == 1)
        ? cycleLength(3 * n + 1) + 1
        : cycleLength(n / 2) + 1;

    if (n < CACHE) memo[n] = result;  // 只有在範圍內才存
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int i, j;
    while (cin >> i >> j)
    {
        cout << i << " " << j << " ";

        int lo = min(i, j), hi = max(i, j);

        int best = 0;
        for (int k = lo; k <= hi; k++)
            best = max(best, cycleLength(k));

        cout << best << "\n";
    }
    return 0;
}
```

**Why it works:**

- 
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
- If you solve a similar problem again, what will you do better?
