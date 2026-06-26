# UVa 540 - Team Queue

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 540
- **Problem Title:** Team Queue
- **Problem Link:** https://onlinejudge.org/external/5/540.pdf
- **Source Code (Fail):** [src/540-fail.cpp](./src/540-fail.cpp)
- **Source Code (Correct/Accepted):** [src/540-correct.cpp](./src/540-correct.cpp)

## 2. Problem Statement in My Own Words

- people belong to teams; when ENQUEUE: if a teammate is already in line, join behind them; else go to the very back
- DEQUEUE: remove from the front as usual
- **Goal: a queue of team sub-queues**
  - main queue tracks the ORDER of teams
  - each team has its own internal queue

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- implement a queue where team members join behind their teammates

### Final Strategy

- `mainQ`: queue of team IDs (order of appearance)
- `teamQ[tid]`: each team's internal queue
- ENQUEUE x: find team of x; if team not in mainQ, add it; push x to teamQ[tid]
- DEQUEUE: pop from front team's internal queue; if that team's queue is now empty, remove team from mainQ
- why it works: mainQ keeps team order; teamQ keeps member order within each team

## 4. Pseudocode

```text
START
1. read teams and build person -> team map
2. ENQUEUE x: if team not in main queue, add it; push x to team's queue
3. DEQUEUE: front team's front person; if team empty, pop from main queue
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/540-fail.cpp](./src/540-fail.cpp))

**Why it failed:**

- read the team definitions but never processed ENQUEUE/DEQUEUE commands

### Correct Code

(See [src/540-correct.cpp](./src/540-correct.cpp))

**Why it works:**

- two-level queue structure: main queue of teams + sub-queue per team
- ENQUEUE checks if team is already present (avoids duplicate team entries)
- DEQUEUE removes team from main queue when its sub-queue empties

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | two-level queue (main + per-team sub-queues) |

### Reflection

- what I learned: "grouped queue" = queue of queues; the main queue tracks group order
- need a flag/set to track which teams are currently in the main queue

* next time: when items have group membership and groups stick together -> queue of queues
