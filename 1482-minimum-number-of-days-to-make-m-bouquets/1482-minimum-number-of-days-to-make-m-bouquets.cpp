class Solution {
public:
    bool possible(vector<int>&arr,int day,int m,int k){
        int cnt=0;
        int noofb=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<=day){
                cnt++;
            }else{
                noofb+=(cnt/k);
                cnt=0;
            }
        }
        noofb+=(cnt/k);
        if(noofb>=m){
            return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=INT_MAX;
        int high=0;
        for(int i=0;i<bloomDay.size();i++){
            low=min(low,bloomDay[i]);
            high=max(high,bloomDay[i]);
        }
        if((long long)m*k>bloomDay.size()){
            return -1;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};