# [UVa] [10035] - [Primary Arithmetic]


## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10035
- **Problem Title:** Primary Arithmetic
- **Problem Link:** https://onlinejudge.org/external/100/10035.pdf
- **Source Code (Fail):** [src/your-file-name.cpp](./src/your-file-name.cpp)
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/your-file-name.cpp)

## 2. Problem Statement in My Own Words

<img width="2196" height="440" alt="IMG_0238" src="https://github.com/user-attachments/assets/23e777e5-93e6-479f-8c03-9126a15017e9" />


- What is the input?
- What is the expected output?
- What are the main rules or constraints?
- What is the core task you must solve?

## 3. Thinking Logic and Solution Strategy


### Initial Thoughts

- What was your first idea?
  A: My first idea is to list the test case a and b in different digits. (e.g. a = 23 and b = 777) 
  
- What difficulty did you notice at the beginning?
  A: A and b might be in different digits, so the difficulty is to NOT process a and b separately.
  
### Final Strategy

- What method did you finally use?
- Why does this method work?
- What edge cases did you consider?
  A: (a, b) = (100000000, 999999999), (111111111 999999999), (0, 9)

## 4. Pseudocode

```text
START
1. Input a and b
2. Add the rightmost digits of a and b, as well as the sum's leftmost digit -> sum
3. If sum >= 10, carry +1
4. Until a == 0 and b == 0, return the carry number to the main function
END
```

## 5. Fail Code vs Correct Code

### Correct Code

```cpp
#include <iostream>
using namespace std;

int count(int a, int b)
{
    int sum = 0, carry = 0;
    
    while(a > 0 || b > 0)
    {
        sum = sum / 10 + a % 10 + b % 10;
        
        if(sum >= 10)
            carry++;
        
        a /= 10;
        b /= 10;
    }
    return carry;
}

int main()
{
    unsigned int a, b;
    while(cin >> a >> b)
    {
        if(a == 0 && b == 0)
            break;
        
        int carry = 0;
        carry = count(a,b);
        
        if(carry == 0)
            cout << "No carry operation.";
        else if(carry == 1)
            cout << "1 carry operation.";
        else
            cout << carry << " carry operations.";
        cout << endl;
    }
}

//123 777
//23 777
//2 777
//3 777

```

**How to improved:**

- 
- 

### Another version (Code written by claude ai)

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int countCarries(string a, string b)
{
    // 補 0 讓兩個字串等長，方便對齊
    int len = max(a.size(), b.size());
    while ((int)a.size() < len) a = "0" + a;
    while ((int)b.size() < len) b = "0" + b;

    int carryCount = 0, carry = 0;

    // 從最右邊（個位）往左掃
    for (int k = len - 1; k >= 0; k--)
    {
        int sum = (a[k] - '0') + (b[k] - '0') + carry;
        if (sum >= 10)
        {
            carry = 1;
            carryCount++;
        }
        else
        {
            carry = 0;
        }
    }
    return carryCount;
}

int main()
{
    string a, b;
    while (cin >> a >> b)
    {
        if (a == "0" && b == "0")
            break;

        int carry = countCarries(a, b);

        if (carry == 0)
            cout << "No carry operation." << endl;
        else if (carry == 1)
            cout << "1 carry operation." << endl;
        else
            cout << carry << " carry operations." << endl;
    }
    return 0;
}
```

**Pseudocode**

```text
START
1. 
2. 
3. 
4. 
END
```

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
