class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size();
        int m=arr2.size();
        bool flag=true;
        int count=0;
        for(int i=0;i<n;i++){
            flag=true;
            for(int j=0;j<m;j++){
                if(abs(arr1[i]-arr2[j])<=d){
                    flag=false;
                }
            }   
            if(flag==true){
                count++;
            }
        }
        return count;
    }
};