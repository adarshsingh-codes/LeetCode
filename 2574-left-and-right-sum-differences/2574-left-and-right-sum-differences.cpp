class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left=0;
        int right=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            right+=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            right=right-nums[i];
            ans.push_back(abs(left-right));
            left+=nums[i];
        }
        return ans;
    }
};