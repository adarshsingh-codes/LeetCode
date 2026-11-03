class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int ans=arr.size();
        int low=0;
        int high=arr.size()-1;
        while(high>=low){
            int mid=(low+high)/2;
            if(arr[mid]>=target){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};