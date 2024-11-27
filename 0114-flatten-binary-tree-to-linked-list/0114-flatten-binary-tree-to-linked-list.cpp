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
    TreeNode* getEnd(TreeNode* root){
        if(!root) return root;
        while(root->right){
            root = root->right;
        }
        while(root->left){
            root =  root->left;
            }
        return root;
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        
        TreeNode* rootRight = root->right;
        if(root -> left){
            flatten(root->left);
            TreeNode* rightEnd = getEnd(root->left);
            root->right = root->left;
            root->left = NULL;
            rightEnd->right = rootRight;
        }
        flatten(rootRight);  
    }
};