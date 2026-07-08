class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int cnt=1;
        int num=-1;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]==arr[i+1]) cnt++;
            else{
                if(cnt==arr[i]) num=arr[i];
                cnt=1;
            }

        }
        if(cnt==arr[arr.size()-1]) num=arr[arr.size()-1];
        return num;
        
    }
};