# [UVa] [10783] - [Odd Sum]


## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10783
- **Problem Title:** Odd Sum
- **Problem Link:** https://onlinejudge.org/external/107/10783.pdf
- **Source Code (Fail):** [src/your-file-name.cpp](./src/your-file-name.cpp)
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/your-file-name.cpp)

## 2. Problem Statement in My Own Words



## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- What was your first idea?
  
- What difficulty did you notice at the beginning?
  
### Final Strategy

- What method did you finally use?
- Why does this method work?
- What edge cases did you consider?

## 4. Pseudocode

```text
START
1.
2.
3.
4.
END
```

## 5. My Code vs Alternative Method

### My Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int c = 1;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        
        if(b < a)
            swap(a,b);
        
        int sum = 0;
        for(int i = a; i <= b; i++)
        {
            if(i % 2 == 1)
                sum += i;
        }
        cout << "Case " << c << ": " << sum << endl;
        c++;
    }
}

```

**How to improved:**

- k
- 

### Alternative Method (Code written by Claude Ai)

```cpp

```

**Pseudocode**

```text
START
1. 
END
```

## 6. Difference and Reflection

### Key Differences

| Item | My Code | Alternative Method |
|---|---|---|
| Logic |  |  |
| Edge Cases |  |  |
| Output Handling |  |
| Other |  |  |

### Reflection

- What mistake did you make?
- What did you learn from debugging this problem?
- If you solve a similar problem again, what will you do better?
