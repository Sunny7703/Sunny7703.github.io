# [LeetCode] [1022] - [Sum of Root To Leaf Binary Numbers]

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 1022
- **Problem Title:** Sum of Root To Leaf Binary Numbers
- **Problem Link:** https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
- **Source Code (Fail):** [src/your-file-name.cpp](./src/your-file-name.cpp)
- **Source Code (Correct/Accepted):** [src/your-file-name.cpp](./src/your-file-name.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- What is the input?
- What is the expected output?
- What are the main rules or constraints?
- What is the core task you must solve?

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- What was your first idea?
- What difficulty did you notice at the beginning?

### Final Strategy

- What method did you finally use?
- Why does this method work?
- What edge cases did you consider?

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. 
2. 
3. 
4. 
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
class Solution
{
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

- 
- 

### Correct Code

```cpp
class Solution
{
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

- 
- 



## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic |  |  |
| Edge Cases |  |  |
| Output Handling |  |  |
| Other |  |  |

### Reflection

- What mistake did you make?
- What did you learn from debugging this problem?
- If you solve a similar problem again, what will you do better?
