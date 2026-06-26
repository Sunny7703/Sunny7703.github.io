# UVa 514 - Rails

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 514
- **Problem Title:** Rails
- **Problem Link:** https://onlinejudge.org/external/5/514.pdf
- **Source Code (Fail):** [src/514-fail.cpp](./src/514-fail.cpp)
- **Source Code (Correct/Accepted):** [src/514-correct.cpp](./src/514-correct.cpp)

## 2. Problem Statement in My Own Words

- trains 1..n enter a station (stack) from one side
- can push to station or pop from station to the output track
- given a target output ordering, check if it's achievable
- **Goal: simulate the stack and see if the target order is possible**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- check if a given train car ordering can be produced using a single stack (station)

### Final Strategy

- keep a pointer `idx` into the target array and `next` (the next car to push)
- if stack top == target[idx]: pop and advance idx
- else if we still have cars to push: push the next one
- else: impossible
- why it works: we must push cars in order 1..n; the only choice is WHEN to pop

## 4. Pseudocode

```text
START
1. read target ordering
2. idx = 0, next = 1, stack st
3. while idx < n:
4. if st.top == target[idx]: pop, idx++
5. else if next <= n: push next++
6. else: impossible
7. if idx == n: Yes; else: No
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/514-fail.cpp](./src/514-fail.cpp))

**Why it failed:**

- only read the target array and created the stack
- never simulated the push/pop process

### Correct Code

(See [src/514-correct.cpp](./src/514-correct.cpp))

**Why it works:**

- simulates the station stack faithfully
- pushes cars in order, pops when top matches target
- correctly detects impossible orderings

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | stack simulation with push/pop |

### Reflection

- what I learned: "can this permutation be produced by a stack?" = simulate it
- the key constraint: cars enter the stack in order 1..n, so push is forced

* next time: for stack-sortable permutation problems, simulate with a stack
