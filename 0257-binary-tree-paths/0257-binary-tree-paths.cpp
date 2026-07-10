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
    void getpath(TreeNode* root,vector<vector<int>>& res, vector<int>& temp){
        if(!root) return;
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            res.push_back(temp);
        }
        getpath(root->left,res,temp);
        getpath(root->right,res,temp);
        temp.pop_back();  
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> res;
        vector<string> ans;
        vector<int> temp;
        getpath(root,res,temp);
        for(int i=0;i<res.size();i++){
            string str="";
            for(int j=0;j<res[i].size();j++){
                str+=to_string(res[i][j]);
                if(j<res[i].size()-1){
                    str+="->";
                }

            }
            ans.push_back(str);
        }
        return ans;
        
        
    }
};