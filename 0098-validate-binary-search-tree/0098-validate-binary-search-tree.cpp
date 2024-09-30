class Solution {
public:
    bool helper(TreeNode* root, long left, long right){
        if (!root)
            return true;
        if (root->val < right && root->val > left){
            return helper(root->left, left, root->val) && helper(root->right, root->val, right);
        }
        return false;
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};