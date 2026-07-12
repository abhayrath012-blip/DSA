class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> ans=image;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        ans[sr][sc]=color;
        int prev=image[sr][sc];
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&ans[nrow][ncol]!=color&&image[nrow][ncol]==prev){
                    ans[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;

        
    }
};