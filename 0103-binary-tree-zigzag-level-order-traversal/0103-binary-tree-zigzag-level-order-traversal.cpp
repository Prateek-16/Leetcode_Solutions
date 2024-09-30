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
    vector<vector<int>> levelOrder(TreeNode* root) {
        bool count = false;
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>temp;
        while(!q.empty()){
            int q_size=q.size();
            for(int i=0;i<q_size;i++){
                TreeNode* curr = q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left != NULL) {
			        q.push(curr->left);
			    }
		        if(curr->right != NULL) {
			        q.push(curr->right);
		        }
            }
            if(count){
                reverse(temp.begin(),temp.end());
            }
            count = !count;
            ans.push_back(temp);
		    temp.clear();
        } 
        return ans;   
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelOrder(root);
        
    }
};