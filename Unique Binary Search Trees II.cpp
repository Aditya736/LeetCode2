class Solution {
public:

    vector<TreeNode*> solve(int start, int end) {

        vector<TreeNode*> ans;

        // Base case
        if(start > end) {
            ans.push_back(NULL);
            return ans;
        }

        // Har number ko root banao
        for(int i = start; i <= end; i++) {

            // Left subtree
            vector<TreeNode*> leftTrees = solve(start, i - 1);

            // Right subtree
            vector<TreeNode*> rightTrees = solve(i + 1, end);

            // Combine all left & right
            for(auto left : leftTrees) {
                for(auto right : rightTrees) {

                    TreeNode* root = new TreeNode(i);

                    root->left = left;
                    root->right = right;

                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {

        if(n == 0) return {};

        return solve(1, n);
    }
};