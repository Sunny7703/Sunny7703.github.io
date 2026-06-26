# UVa 10935 - Throwing cards away

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 10935
- **Problem Title:** Throwing cards away
- **Problem Link:** https://onlinejudge.org/external/109/10935.pdf
- **Source Code (Fail):** [src/10935-fail.cpp](./src/10935-fail.cpp)
- **Source Code (Correct/Accepted):** [src/10935-correct.cpp](./src/10935-correct.cpp)

## 2. Problem Statement in My Own Words

- cards 1..n in a pile
- repeat: discard top card, move new top to bottom
- print discarded cards and the remaining card
- **Goal: simulate with a queue**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- simulate discarding top card then moving new top to bottom, until 1 card left

### Final Strategy

- queue of 1..n
- while size > 1: pop front (discard), then pop front and push to back (move)
- print discards with commas, then remaining
- edge cases: n = 1 (no discards, just print remaining)

## 4. Pseudocode

```text
START
1. queue = [1..n]
2. while size > 1:
3. discard front; pop
4. push front to back; pop
5. print remaining
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/10935-fail.cpp](./src/10935-fail.cpp))

**Why it failed:**

- built the queue but never simulated the process

### Correct Code

(See [src/10935-correct.cpp](./src/10935-correct.cpp))

**Why it works:**

- queue perfectly models the pile (front = top)
- pop + push-to-back = "move top to bottom"
- stops when 1 card left

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | queue simulation: pop discard, pop-push move |

### Reflection

- what I learned: "circular pile" or "rotate and remove" -> queue
- the output format has commas between discards (tricky: no comma before the first one)

* next time: circular processes -> queue; watch the output format
