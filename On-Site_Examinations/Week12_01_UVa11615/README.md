# UVa 11615 - Family Tree

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11615
- **Problem Title:** Family Tree
- **Problem Link:** https://onlinejudge.org/external/116/11615.pdf
- **Source Code (Fail):** [src/11615-fail.cpp](./src/11615-fail.cpp)
- **Source Code (Correct/Accepted):** [src/11615-correct.cpp](./src/11615-correct.cpp)

## 2. Problem Statement in My Own Words

- complete binary tree with `n` nodes (numbered 1..n, root = 1)
- given two nodes a and b, find their LCA (lowest common ancestor)
- Output: number of nodes NOT in the LCA's subtree = n - (size of LCA's subtree)
- **Goal: find LCA, count its subtree, subtract from n**

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- in a complete binary tree, given two members, count family members NOT in their common subtree

### Final Strategy

- LCA: keep dividing the larger node by 2 until they meet (parent = node/2)
- count nodes in LCA's subtree: BFS level by level from LCA
  - level starts at [lca, lca]; next level is [lca*2, lca*2+1]; cap at n
- answer = n - subtree count
- why it works: in a complete binary tree numbered 1..n, children of x are 2x and 2x+1

## 4. Pseudocode

```text
START
1. while a != b: if a > b: a /= 2; else b /= 2 (find LCA)
2. count nodes from LCA downward (each level: lo..min(hi, n))
3. print n - count
END
```

## 5. Fail Code vs Correct Code

### Fail Code

(See [src/11615-fail.cpp](./src/11615-fail.cpp))

**Why it failed:**

- read n, a, b but never found the LCA or counted

### Correct Code

(See [src/11615-correct.cpp](./src/11615-correct.cpp))

**Why it works:**

- LCA by repeatedly halving the larger -> O(log n)
- subtree count by expanding [lo, hi] each level -> O(log n)
- answer = n - subtreeSize

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | empty | LCA by halving + subtree count by level expansion |

### Reflection

- what I learned: complete binary tree -> parent = x/2, children = 2x and 2x+1
- LCA: keep halving the deeper node until they meet

* next time: binary tree with numbering 1..n -> arithmetic on node numbers instead of pointers
