class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0;
        int maxi=0;
        int prod=1;
        if(k<=1){
            return 0;
        }
        for(int right=0;right<nums.size();right++){
            prod=prod*nums[right];
            while(prod>=k){
                prod=prod/nums[left];
                left++;
            }
            maxi=maxi+(right-left+1);
        }
        return maxi;
    }
};