# [UVa] [11364] - [Optimal Parking]

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11364
- **Problem Title:** Optimal Parking
- **Problem Link:** https://onlinejudge.org/external/113/11364.pdf
- **Source Code (Fail):** [src/wa.cpp](./src/wa.cpp)
- **Source Code (Correct/Accepted):** [src/ac.cpp](./src/ac.cpp)

## 2. Problem Statement in My Own Words

Michael wants the minimum distance between his car and the stores he shopped, but back and forth.

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
1. Getting the test cases, numbers of shops, and the positions they are.
2. Let maximum be minimium and minimum be maximum.
3. If the positions are bigger or smaller than maximum or minimum, the can replace them and get the real maximum and minimum.
4. Beacuse the stores are on a straight line, so by subtracting maximum and minimum can get the minimum distance.
5. [What I made a mistake on] But to *2 (Walk to the stores and walk back to the parking spots)
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
// Paste the incorrect, incomplete, or rejected version here.
```

**Why it failed:**

- I didn't consider to walk by, so the answer /2. 
- By struture wasn't clear enough to decode quickly, so I don't get enough time to correct my code.

### Correct Code

```cpp
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int n, x[20];
    while(t--)
    {
        int max = 0;
        int min = 99;
        
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> x[i];
        }
        
        for(int i = 0; i < n; i++)
        {
            if(x[i] > max)
                max = x[i];
            if(x[i] < min)
                min = x[i];
        }
        
        cout << (max - min) * 2 << endl;
    }
    return 0;
}

```

**Why it works:**

- By multiplying 2 to get the real distance from walking to the stores and walking back to the car.
- Clearly structured, easy to find the problem.



## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | Forgot the walk back to the car |  |
| Edge Cases | x | x |
| Output Handling | x | x |
| Other | messy structure | clear structure |

### Reflection

- What mistake did you make?
- What did you learn from debugging this problem?
- If you solve a similar problem again, what will you do better?
