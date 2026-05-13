# [Platform] [Problem ID] - [Problem Title]

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa / LeetCode
- **Problem ID:** 
- **Problem Title:** 
- **Problem Link:** 
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
using namespace std;

int main()
{
    int I;
    while(cin >> I && I != 0)
    {
        int one = 0;
        cout << "The parity of ";
        for(int i = 30; i >= 0; i--)
        {
            if(I >= pow(2, i))
            {
                cout << "1";
                I -= pow(2, i);
                one++;
            }
            else if(I < pow(2, i) && i != 0)
                cout << "0";
        }
        
        cout << " is " << one << " (mod 2). "<< endl;
    }
    return 0;
}


```

**Why it failed:**

- 
- 

### Correct Code

```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        string bin = "";
        int ones = 0;
        int tmp = n;

        while (tmp > 0)
        {
            int bit = tmp % 2;
            if (bit == 1) ones++;
            bin = (char)('0' + bit) + bin;
            tmp /= 2;
        }

        cout << "The parity of " << bin
             << " is " << ones
             << " (mod 2)." << endl;
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
