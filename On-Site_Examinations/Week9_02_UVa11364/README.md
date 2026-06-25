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
- Input: number of test cases T; each case has N stores and their positions on a number line
- Output: minimum total walking distance — from parking spot, through all stores, back to parking spot
- Constraints: parking at position 0, store positions 1–99, at most 20 stores
- **Goal: find the cheapest valid (hotel, weekend) combo**

## 3. Thinking Logic and Solution Strategy
Explain how you thought about the problem and how you decided on your final approach.
### Initial Thoughts
- What was your first idea?
- What difficulty did you notice at the beginning?
### Final Strategy
- find max and min positions among all stores
- answer = `(max - min) * 2`
- works because all stores are on a line — one pass from min to max covers all, then multiply by 2 for the return
- edge case: only one store → min == max → answer is 0 (handled by the formula automatically)

## 4. Pseudocode
```text
START
1. Getting the test cases, numbers of shops, and the positions they are.
2. Let maximum be minimium and minimum be maximum.
3. If the positions are bigger or smaller than maximum or minimum, the can replace them and get the real maximum and minimum.
4. Beacuse the stores are on a straight line, so by subtracting maximum and minimum can get the minimum distance.
MISTAKE
5. But to *2 (Walk to the stores and walk back to the parking spots)
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
    int t, n, x[20];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> x[i];
        int mx = 0, mn = 99;
        for(int i = 0; i < n; i++)
        {
            if(x[i] > mx) mx = x[i];
            if(x[i] < mn) mn = x[i];
        }
        cout << (mx - mn) << endl;
    }
    return 0;
}
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
| Logic | Forgot the walk back to the car |  `(max - min) * 2` correctly accounts for both directions |
| Edge Cases | x | x |
| Output Handling | x | x |
| Other | messy structure | clear structure |
### Reflection
- my mistake: only thought about walking to the farthest store — forgot Michael has to return to the parking spot, so missing the ×2
- what I learned: when the problem mentions a round trip, mark it explicitly in the pseudocode before writing any code; clean structure also speeds up debugging under time pressure
- next time: first confirm whether the start point needs to be returned to; if yes, note ×2 immediately in the pseudocode
