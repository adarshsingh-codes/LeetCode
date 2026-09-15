class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                int currdiff=abs(target-sum); //how far the curr sum is from the target
                int prevclose=abs(target-close); // how far my previous sum was from target
                if(currdiff<prevclose){ //if th eurrent sum is closer then we consider that
                    close=sum;
                }    
                if(sum==target){
                    return target;
                }else if(sum<target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return close;
    }
};