class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        unordered_map<int,int> mpp;
        sort(temp.begin(),temp.end());
        int cnt=1;
        for(int i=0;i<temp.size();i++){
            if(mpp.find(temp[i])==mpp.end()){
                mpp[temp[i]]=cnt;
                cnt++;
            }
            
        }
        for(int i=0;i<arr.size();i++){
            temp[i]=mpp[arr[i]];
        }
        return temp;
        
        
    }
};