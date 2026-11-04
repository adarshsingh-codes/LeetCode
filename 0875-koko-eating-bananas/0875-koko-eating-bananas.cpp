class Solution {
public:
    long long calchrs(vector<int>&piles,int rate){
        long long  total=0;
        for(int i=0;i<piles.size();i++){
            total+=ceil((double)piles[i]/(double)rate);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=0;
        for(int i=0;i<piles.size();i++){
            high=max(high,piles[i]);
        }
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            long long totalhrs=calchrs(piles,mid);
            if(totalhrs<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};