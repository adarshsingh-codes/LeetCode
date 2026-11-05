class Solution {
public:
    long long  func(vector<int>&arr,int mid){
        long long sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/(double)mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=0;
        for(int i=0;i<nums.size();i++){
            high=max(high,nums[i]);
        }
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};