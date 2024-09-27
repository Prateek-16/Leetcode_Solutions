/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void mapping(vector<int>& inorder, unordered_map<int, int>& mp) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& pre_size,
                    unordered_map<int, int>& mp, int in_start, int in_end,
                    int& index) {
        if (in_start > in_end || index >= pre_size) {
            return NULL;
        }
        int ele = preorder[index];
        TreeNode* root = new TreeNode(ele);
        int pos = mp[ele];
        index++;
        root->left =
            solve(preorder, inorder, pre_size, mp, in_start, pos - 1, index);
        root->right =
            solve(preorder, inorder, pre_size, mp, pos + 1, in_end, index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        mapping(inorder, mp);
        int index = 0;
        int in_start = 0;
        int in_end = inorder.size() - 1;
        int pre_size = preorder.size();
        TreeNode* root =
            solve(preorder, inorder, pre_size, mp, in_start, in_end, index);
        return root;
    }
};