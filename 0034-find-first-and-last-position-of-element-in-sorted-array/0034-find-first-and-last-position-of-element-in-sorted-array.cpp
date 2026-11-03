class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int ans1=-1;
        int low=0;
        int high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=target){
                ans1=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        if(ans1==-1||arr[ans1]!=target){
            return {-1,-1};
        }
        low=0;
        high=arr.size()-1;
        int ans2=arr.size();
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>target){
                ans2=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {ans1,ans2-1};
    }
};