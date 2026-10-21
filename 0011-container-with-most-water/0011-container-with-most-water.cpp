class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        int maxi=INT_MIN;
        int best=0;
        while(i<j){
            maxi=min(arr[i],arr[j])*(j-i);
            best=max(maxi,best);
            if(arr[i]<arr[j]){
                i++;
            }
            else if(arr[i]>arr[j]){
                j--;
            }else{
                i++;
                j--;
            }
        }
        return best;
    }
};