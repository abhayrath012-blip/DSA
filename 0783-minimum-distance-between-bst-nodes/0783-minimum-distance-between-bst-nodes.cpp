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
class BSTiterator{
    private: 
        stack<TreeNode*> mystack;
    public:
        BSTiterator(TreeNode* root){
            pushall(root);
        }
        bool hasnext(){
            return !mystack.empty();
        }
        int next(){
            TreeNode* tmpnode=mystack.top();
            mystack.pop();
            pushall(tmpnode->right);
            return tmpnode->val;

        }
    private:
        void pushall(TreeNode* root){
            while(root){
                mystack.push(root);
                root=root->left;
            }
        }

};
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        int mini=INT_MAX;
        BSTiterator help(root);
        int prev=help.next();
        while(help.hasnext()){
            int cur=help.next();
            mini=min(mini,abs(cur-prev));
            prev=cur;
            
        }
        return mini;
        
    }
};