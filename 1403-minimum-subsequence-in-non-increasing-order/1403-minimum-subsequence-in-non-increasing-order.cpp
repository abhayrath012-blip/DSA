class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        int index=-1;
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return nums;
        int i=-1,j=nums.size(),leftsum=0,rightsum=0;
        while(i<=j){
            if(rightsum-leftsum>0){
                if(index!=j){
                    ans.push_back(nums[j]);
                    index=j;
                }
                i++;
                leftsum+=nums[i];
            }
            else{
                j--;
                rightsum+=nums[j];
            }
        }
        return ans;
        
    }
};