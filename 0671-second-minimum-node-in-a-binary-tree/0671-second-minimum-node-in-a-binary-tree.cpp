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
    int findSecondMinimumValue(TreeNode* root) {
        map<int,int> mpp;
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(mpp.find(node->val)==mpp.end()){
                    mpp[node->val]=1;
                    cnt++;
                }
                if(node->left&&node->right){
                    q.push(node->left);
                    q.push(node->right);
                }

            }
        }
        int num;
        if(cnt<2) return -1;
        int count=2;
        for(auto it:mpp){
            num=it.first;
            count--;
            if(count==0) break;

        }
        return num;

        
    }
};