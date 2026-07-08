class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int cnt=0;
        for(int i=0;i<arr1.size();i++){
            if(bs(arr1[i],arr2,d)){
                cnt++;
            }
        }
        return cnt;

    }
    bool bs(int num,vector<int>& arr2,int &d){
        int low=0,high=arr2.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(abs(num-arr2[mid])<=d) return false;
            if((num-arr2[mid])<=0) high=mid-1;
            else low=mid+1;
        }
        return true;
        
    }
};