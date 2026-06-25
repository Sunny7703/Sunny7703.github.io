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
