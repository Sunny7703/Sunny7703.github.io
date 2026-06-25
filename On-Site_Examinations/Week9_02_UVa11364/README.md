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
- **What is the input?** Number of test cases T, and for each case: the number of stores N, and the position of each store on a number line.
- **What is the expected output?** For each test case: the minimum total distance Michael needs to walk — from the parking spot, visiting all stores, and returning to the parking spot.
- **What are the main rules or constraints?** Parking spot is fixed at position 0. Store positions are integers from 1 to 99. At most 20 stores per test case.
- **What is the core task you must solve?** Find the max and min positions among all stores. Since walking from min to max (or vice versa) covers all stores in one trip, the answer is (max - min) * 2.
## 3. Thinking Logic and Solution Strategy
Explain how you thought about the problem and how you decided on your final approach.
### Initial Thoughts
- First idea was to find the farthest store and calculate the round-trip distance to it.
- Didn't think carefully about the "return to parking spot" condition at first — only computed one-way distance.
### Final Strategy
- Find the maximum and minimum positions among all stores.
- Answer = (max - min) * 2.
- This works because all stores are on a straight line; walking from min to max (or max to min) covers everything in one pass, and we must return, so multiply by 2.
- Edge case: only one store → min == max → answer is 0 (handled automatically by the formula).
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
- My structure wasn't clear enough to debug quickly, so I didn't get enough time to correct my code.
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
| Logic | Forgot to multiply by 2 for the return trip; only computed `(max - min)` | `(max - min) * 2` correctly accounts for both directions |
| Edge Cases | Not explicitly considered, but the formula still handles single-store input correctly | Single store outputs 0 automatically |
| Output Handling | Output value was wrong (half the correct answer) | Output is correct |
| Other | Messy structure, hard to spot the bug under time pressure | Clean, well-organized structure, easy to locate the problem |
### Reflection
- **What mistake did you make?** I only thought about "walking to the farthest store" and forgot that Michael has to walk back to the parking spot — missing the ×2.
- **What did you learn from debugging this problem?** When the problem mentions a round trip, mark it explicitly in the pseudocode before writing any code. Clean code structure also speeds up debugging significantly.
- **If you solve a similar problem again, what will you do better?** First confirm whether the starting point needs to be returned to. If yes, note ×2 in the pseudocode immediately. Also plan the code structure before writing to avoid messy code under pressure.
