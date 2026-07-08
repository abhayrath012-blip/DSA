class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> ans;
        unordered_set<int> st;
        for(int i=0;i<m;i++){
            int col=findmin(matrix[i]);
            int mini=matrix[i][col];
            if(st.count(col)==0){
                if(miniismax(mini,matrix,col)){
                    ans.push_back(mini);
                    st.insert(col);
                }
            }
        }
        return ans;   
    }
    int findmin(vector<int> row){
        int mini=INT_MAX,index;
        for(int i=0;i<row.size();i++){
            if(row[i]<mini){
                mini=row[i];
                index=i;
            }
        }
        return index;

    }
    bool miniismax(int maxi,vector<vector<int>>& matrix,int col){
        int m=matrix.size();
        for(int i=0;i<m;i++){
            if(matrix[i][col]>maxi) return false;
        }
        return true;
        
    }
};