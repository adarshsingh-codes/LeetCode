class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int sum=0;
        int maxi=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                sum++;
            }
            while(sum>k){
                if(nums[left]==0){
                    sum--;
                }
                left++;
            }   
            maxi=max(maxi,right-left+1);
        }
        return  maxi;
    }
};