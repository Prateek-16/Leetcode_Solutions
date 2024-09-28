/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int& ans){
        if(!root){
            return 0;
        }
        //Positive left and right maximum Path
        int leftAns = max(0,solve(root->left,ans));
        int rightAns = max(0,solve(root->right,ans));
        
        //Updating ans after considering root as a part of Maximum sum path
        ans = max(ans, leftAns + rightAns + root->val);
        
        //Returning the maximum path + root
        return max(leftAns,rightAns) + root->val;
        
    }
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;  //To Store the maximum
        solve(root,ans);
        return ans;
    }
};