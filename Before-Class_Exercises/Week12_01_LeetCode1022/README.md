# LeetCode 1022 - Sum of Root To Leaf Binary Numbers

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1022
- **Problem Title:** Sum of Root To Leaf Binary Numbers
- **Problem Link:** https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
- **Source Code (Fail):** [src/lc1022-fail.cpp](./src/lc1022-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc1022-correct.cpp](./src/lc1022-correct.cpp)

## 2. Problem Statement in My Own Words

- a binary tree where every node is 0 or 1
- each root-to-leaf path reads as a binary number (root is the highest bit)
- Input: the root of the tree
- Output: sum of ALL root-to-leaf binary numbers (as a decimal int)
- **Goal: walk each root-to-leaf path, build the binary number along the way, add them up**
  - only LEAF endings count -> a missing child is NOT a path

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: DFS, carry the current value down
- at each node: shift left and OR the new bit -> `cv = cv * 2 + node->val`
- when we reach a leaf -> add `cv` to the total
- tricky bit: what should `nullptr` return? this is where the bug lives

### Final Strategy

- recursive helper `helper(node, cv)`:
  - if `node == nullptr` -> return 0 (no path here, contribute nothing)
  - update `cv = cv * 2 + node->val`
  - if leaf (both children null) -> return `cv` (the finished number)
  - else -> return `helper(left, cv) + helper(right, cv)`
- why it works:
  - only leaves return a number; `nullptr` returns 0 so a missing child doesn't add a fake path
  - shifting left and adding the bit builds the binary number as we go down
- edge cases:
  - single node -> goes straight to the leaf branch, returns its value
  - node with ONLY a left (or only a right) child -> the missing side must NOT be counted; `nullptr -> 0` handles it
  - perfect tree -> both versions agree (no nullptr ever returned to the sum)

## 4. Pseudocode

```text
START
1. helper(node, cv):
2. if node is null: return 0
3. cv = cv * 2 + node.val
4. if node is leaf: return cv
5. return helper(node.left, cv) + helper(node.right, cv)
6. sumRootToLeaf(root): return helper(root, 0)
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution{
public:
    int helper(TreeNode* node, int currentVal)
    {
        if (node == nullptr) return currentVal;
        currentVal = currentVal * 2 + node->val;
        if (node->left == nullptr && node->right == nullptr) return currentVal;
        return helper(node->left, currentVal) + helper(node->right, currentVal);
    }
    int sumRootToLeaf(TreeNode* root)
    {
        return helper(root, 0);
    }
};
```

**Why it failed:**

- on `nullptr`, returns `currentVal` (the ancestor's running value) instead of 0
- this only matters when a node has ONE child (the other is null) -> the null side wrongly adds the parent's value as if it were a finished path
- the same parent path gets counted on BOTH sides -> the value is added once for the real leaf and again for the null sibling -> total is too big
- example: tree `1 -> left 0, right null`
  - real path: `10` (binary) = 2
  - fail returns: 2 (real leaf) + 1 (null right, ancestor `1`) = 3 (wrong)
- perfect trees pass by accident (no null ever reaches the sum), so the bug only shows on uneven trees

### Correct Code

```cpp
class Solution{
public:
    int helper(TreeNode* node, int currentVal)
    {
        if (node == nullptr) return 0;
        currentVal = currentVal * 2 + node->val;
        if (node->left == nullptr && node->right == nullptr) return currentVal;
        return helper(node->left, currentVal) + helper(node->right, currentVal);
    }
    int sumRootToLeaf(TreeNode* root)
    {
        return helper(root, 0);
    }
};
```

**Why it works:**

- `nullptr` -> return 0 -> a missing child adds nothing
- only LEAVES return `currentVal` -> only complete root-to-leaf paths get summed
- the shift `cv = cv * 2 + node->val` is the standard "build binary while walking down"

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | `nullptr` returns `currentVal` -> phantom path | `nullptr` returns 0 -> no phantom path |
| Edge Cases | wrong for any node with ONE child | right for every shape (single child, leaf, perfect) |
| Output Handling | total too big (double-counts parent value at each one-child node) | total exactly equals the sum of real paths |
| Other | only perfect trees happen to pass | works on all valid trees |

### Reflection

- my mistake: thought `nullptr -> currentVal` would "carry the value up", but that's exactly what makes a fake path
- what I learned:
  - in tree DFS, decide carefully what the BASE CASE returns -> `nullptr` should usually return the IDENTITY of the operation (here: 0 for sum)
  - "leaf" is `left == null && right == null`; that's the only place a real path ends
  - perfect-tree test cases can hide this bug

* next time: write the recursion intent first ("`nullptr` is not a path -> return 0") before coding; mentally test on a tree with a single child to catch this kind of slip
