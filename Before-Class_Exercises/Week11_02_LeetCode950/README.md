# LeetCode 950 - Reveal Cards In Increasing Order

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 950
- **Problem Title:** Reveal Cards In Increasing Order
- **Problem Link:** https://leetcode.com/problems/reveal-cards-in-increasing-order/description/
- **Source Code (Fail):** [src/lc950-fail.cpp](./src/lc950-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc950-correct.cpp](./src/lc950-correct.cpp)

## 2. Problem Statement in My Own Words

- reveal process: take top card (reveal it), then move next top card to the bottom; repeat
- want the revealed order to be INCREASING
- return the deck ordering that achieves this
- **Goal: arrange the deck so the reveal process produces sorted output**
  - simulate the process in REVERSE

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- simulating forward is hard (which card goes where?)
- reverse simulation: start from the largest card, undo each step

### Final Strategy

- sort the deck
- use a deque, process from largest to smallest:
  - if deque is not empty: move back to front (undo the "top to bottom" move)
  - push current card to front (undo the "reveal")
- the deque at the end is the answer
- why it works: reversing the reveal process undoes each step perfectly
- edge cases: single card, two cards

## 4. Pseudocode

```text
START
1. sort deck ascending
2. dq = empty deque
3. for i = n-1 down to 0:
4. if dq not empty: move dq.back to dq.front
5. push deck[i] to dq.front
6. return dq as vector
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> dq;



        return vector<int>(dq.begin(), dq.end());
    }
};
```

**Why it failed:**

- sorted the deck but never built the deque -> returns empty

### Correct Code

```cpp
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> dq;
        for (int i = n - 1; i >= 0; i--) {
            if (!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};
```

**Why it works:**

- reverse simulation: "move back to front" undoes "move top to bottom"
- "push to front" undoes "reveal top card"
- processing from largest to smallest ensures the final reveal is in increasing order

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | reverse simulation with deque |
| Edge Cases | none | single card, two cards |
| Output Handling | returns empty | returns correct ordering |
| Other | only setup | O(n log n) for sort, O(n) for deque |

### Reflection

- what I learned: "what input produces this output?" -> simulate the process in REVERSE
- deque is perfect for "move back to front" operations

* next time: when forward simulation is hard, try reversing the process
