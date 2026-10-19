class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0;
        int maxi=0;
        int maxcount=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                maxcount++;
            }
            while(maxcount>1){
                if(nums[left]==0){
                    maxcount--;
                }
                left++;
            }
            maxi=max(maxi,right-left);
        }
        return maxi;
    }
};