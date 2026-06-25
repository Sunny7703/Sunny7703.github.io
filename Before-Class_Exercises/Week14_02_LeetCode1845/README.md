# LeetCode 1845 - Seat Reservation Manager

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1845
- **Problem Title:** Seat Reservation Manager
- **Problem Link:** https://leetcode.com/problems/seat-reservation-manager/description/
- **Source Code (Fail):** [src/lc1845-fail.cpp](./src/lc1845-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc1845-correct.cpp](./src/lc1845-correct.cpp)

## 2. Problem Statement in My Own Words

- seats numbered 1..n
- `reserve()` -> return the SMALLEST available seat
- `unreserve(seatNumber)` -> free that seat
- **Goal: always give the smallest available seat efficiently**
  - min-heap of available seats

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- bool array + linear scan -> O(n) per reserve, too slow
- min-heap -> O(log n) per operation

### Final Strategy

- init: push 1..n into a min-heap
- `reserve()`: pop the top (smallest available)
- `unreserve(x)`: push x back
- why it works: min-heap always gives the smallest in O(log n)
- edge cases: unreserve then reserve the same seat, interleaved operations

## 4. Pseudocode

```text
START
SeatManager(n): push 1..n into min-heap
reserve(): return pq.pop()
unreserve(x): pq.push(x)
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) pq.push(i);
    }
    int reserve() {

    }
    void unreserve(int seatNumber) {

    }
};
```

**Why it failed:**

- initialized the heap but never implemented reserve or unreserve

### Correct Code

```cpp
class SeatManager {
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) pq.push(i);
    }
    int reserve() {
        int s = pq.top(); pq.pop();
        return s;
    }
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
```

**Why it works:**

- min-heap keeps the smallest seat on top -> `reserve()` is O(log n)
- `unreserve()` pushes back -> O(log n)
- the heap automatically re-sorts after each push/pop

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty methods | pop top for reserve, push for unreserve |
| Edge Cases | none | re-reserve freed seats correctly |
| Output Handling | undefined | returns smallest available |
| Other | only init | O(log n) per operation |

### Reflection

- what I learned: "always give the smallest available" -> min-heap
- `priority_queue<int, vector<int>, greater<int>>` is the C++ min-heap

* next time: "smallest / largest available" -> heap; if "both" -> two heaps or a set
