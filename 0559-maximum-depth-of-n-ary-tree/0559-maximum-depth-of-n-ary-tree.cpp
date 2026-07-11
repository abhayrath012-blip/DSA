/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==NULL) return 0;
        int height=0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            height++;
            for(int i=0;i<size;i++){
                Node* n=q.front();
                q.pop();
                for(Node* child:n->children){
                    q.push(child);
                }
            }
        }
        return height;
        
    }
};