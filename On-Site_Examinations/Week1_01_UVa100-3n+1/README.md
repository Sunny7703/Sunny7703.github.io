# [UVa] [100] - [3n+1]


## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 100
- **Problem Title:** The 3n + 1 problem
- **Problem Link:** https://onlinejudge.org/external/1/100.pdf
- **Source Code (Original code):** [src/your-file-name.cpp](./src/your-file-name.cpp)
- **Source Code (Impoved code):** [src/your-file-name.cpp](./src/your-file-name.cpp)

## 2. Problem Statement in My Own Words

According to the algorithm, not until n = 1, the cycle count will be added once by running one step. From the input i and j, I need to output the maximum cycle count from the range i to j, including themselves. 


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

## 5. Original Code vs Improved Code

Show the code that failed first, then show the corrected version.

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

**Why it failed:**

- 
- 

### Improved Code

```cpp
// Paste the corrected or accepted version here.
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
