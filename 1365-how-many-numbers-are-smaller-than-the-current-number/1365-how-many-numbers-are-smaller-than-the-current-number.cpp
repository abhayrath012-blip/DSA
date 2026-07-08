class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int,int> mpp;
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(mpp.find(temp[i])==mpp.end()){
                mpp[temp[i]]=i;
            }
        }
        for(int i=0;i<nums.size();i++){
            int index=mpp[nums[i]];
            nums[i]=index;
        }
        return nums;
        
    }
};