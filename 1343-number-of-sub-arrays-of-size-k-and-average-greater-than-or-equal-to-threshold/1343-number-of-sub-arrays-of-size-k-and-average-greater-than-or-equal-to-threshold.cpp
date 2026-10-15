class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int count=0;
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int maxi=sum;
        double avg=maxi/k;
        for(int i=k;i<nums.size();i++){
            if(avg>=threshold){
                count++;
            }
            sum+=nums[i];
            sum-=nums[i-k];
            maxi=max(sum,maxi);
            avg=(double)sum/k;
        }
        if(avg>=threshold){
            count++;
        }
        return count;
    }
};