class Solution {
public:

    bool solve(TreeNode* root, long long minVal, long long maxVal) {

        if(root == NULL) {
            return true;
        }

        // BST condition
        if(root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        // Left subtree
        bool left = solve(root->left, minVal, root->val);

        // Right subtree
        bool right = solve(root->right, root->val, maxVal);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {

        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};