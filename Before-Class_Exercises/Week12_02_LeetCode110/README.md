# [LeetCode] [110] - [Balanced Binary Tree]

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 110
- **Problem Title:** Balanced Binary Tree
- **Problem Link:** https://leetcode.com/problems/balanced-binary-tree/description/
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

- 
- 

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
