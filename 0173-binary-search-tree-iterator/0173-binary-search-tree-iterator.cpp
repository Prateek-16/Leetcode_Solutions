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
class BSTIterator {
private:
    vector<int>inorder;
    int itrator = 0;
public:
    void getInorder(TreeNode* root,vector<int>& inorder){
        if(root == NULL){
            return;
        }
        getInorder(root->left,inorder);
        inorder.push_back(root->val);
        getInorder(root->right,inorder);
        return;
    }
    
    BSTIterator(TreeNode* root) {
        getInorder(root,inorder);    
    }
    
    int next() {
        return inorder[itrator++];
        
    }
    
    bool hasNext() {
        if(itrator < inorder.size())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */