# LeetCode 110 - Balanced Binary Tree

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 110
- **Problem Title:** Balanced Binary Tree
- **Problem Link:** https://leetcode.com/problems/balanced-binary-tree/description/
- **Source Code (Fail):** [src/lc110-fail.cpp](./src/lc110-fail.cpp)
- **Source Code (Correct/Accepted):** [src/lc110-correct.cpp](./src/lc110-correct.cpp)

## 2. Problem Statement in My Own Words

- a "height-balanced" tree means EVERY node has `|leftHeight - rightHeight| <= 1`
- Input: root of a binary tree
- Output: `true` if every node is balanced, `false` if any node breaks the rule
- **Goal: check the balance condition at EVERY node, not just the root**
  - height of null = 0
  - height of a node = `max(leftHeight, rightHeight) + 1`

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

- first idea: get the left and right heights of root and compare -> WRONG, that's only one node
- the definition says EVERY node, so I have to check all of them, not just root

### Final Strategy

- `getHeight(node)`:
  - null -> 0
  - otherwise -> `max(leftHeight, rightHeight) + 1`
- `isBalanced(root)`:
  - null -> true
  - check this node: `|leftH - rightH| <= 1`
  - AND recursively `isBalanced(left)` and `isBalanced(right)`
- why it works:
  - the definition is "for every node" -> the recursion must visit every node
  - short-circuit AND -> as soon as one node is unbalanced, return false
- edge cases:
  - empty tree -> balanced (vacuously)
  - single node -> balanced (both heights are 0)
  - tree that LOOKS balanced at root but is unbalanced deeper -> the recursive check catches it
- complexity:
  - this version is `O(n^2)` worst case (re-computing heights)
  - a smarter version returns height AND a balanced flag in one pass -> `O(n)`

## 4. Pseudocode

```text
START
1. getHeight(node):
2. if node is null: return 0
3. return max(getHeight(left), getHeight(right)) + 1

4. isBalanced(root):
5. if root is null: return true
6. if |getHeight(left) - getHeight(right)| > 1: return false
7. return isBalanced(left) AND isBalanced(right)
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
class Solution {
public:
    int getHeight(TreeNode* node)
    {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr) return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return abs(leftHeight - rightHeight) <= 1;
    }
};
```

**Why it failed:**

- only checks the balance at ROOT, not at every node
- the problem's definition is "every node is balanced", not "root is balanced"
- a tree can have equal left and right heights at root but be unbalanced inside
- counter-example tree:
  ```
        1
       / \
      2   2
     /     \
    3       3
   /         \
  4           4
  ```
  - root: leftH = 3, rightH = 3, diff = 0 -> fail says "balanced"
  - but node `2` on the left: leftH = 2, rightH = 0, diff = 2 -> NOT balanced
  - correct answer: `false`; fail returns `true` (WA)

### Correct Code

```cpp
class Solution {
public:
    int getHeight(TreeNode* node)
    {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root)
    {
        if (root == nullptr) return true;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return abs(leftHeight - rightHeight) <= 1
            && isBalanced(root->left)
            && isBalanced(root->right);
    }
};
```

**Why it works:**

- checks this node's balance
- AND recursively checks the left subtree
- AND recursively checks the right subtree
- so EVERY node gets the same balance test -> matches the definition
- short-circuit `&&` stops as soon as one subtree returns false

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | only checks root | checks every node via recursion |
| Edge Cases | misses deeper imbalance hidden under equal root heights | catches imbalance at any depth |
| Output Handling | returns `true` for some unbalanced trees | returns the right boolean for every tree |
| Other | no recursion on subtrees in `isBalanced` | recursive `&& isBalanced(left) && isBalanced(right)` |

### Reflection

- my mistake: read "balanced" but only translated "root balanced"; the definition says EVERY node
- what I learned:
  - "for every node" -> the recursion must reach every node, not just the entry point
  - balanced root + balanced height numbers does NOT mean balanced tree
  - a quick sanity test: an unbalanced subtree on one side and a matching height on the other can fool a root-only check

* next time:
  - re-read "for every" / "for all" carefully; that word always means recurse
  - this version is `O(n^2)` (heights are recomputed). A one-pass `O(n)` trick: have `getHeight` return -1 to mean "unbalanced somewhere below", and bubble that up; if any subtree returns -1, the whole tree is unbalanced
