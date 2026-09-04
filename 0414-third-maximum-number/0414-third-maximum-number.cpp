class Solution {
public:
    int thirdMax(vector<int>& arr) {
        long maxi=LONG_MIN;
        long sec_maxi=LONG_MIN;
        long third_maxi=LONG_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxi){
                third_maxi=sec_maxi;
                sec_maxi=maxi;
                maxi=arr[i];
            }else if(arr[i]>sec_maxi&&arr[i]!=maxi){
                third_maxi=sec_maxi;
                sec_maxi=arr[i];
            }else if(arr[i]>third_maxi&&arr[i]!=maxi&&arr[i]!=sec_maxi){
                third_maxi=arr[i];
            }
        }
        if(third_maxi!=LONG_MIN){
            return third_maxi;
        }
        return maxi;
    }
};