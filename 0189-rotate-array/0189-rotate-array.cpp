class Solution {
public:
    void reversearr(vector<int>&arr,int start,int end){
        int i=start;
        int j=end-1;
        while(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reversearr(nums,0,nums.size());
        reversearr(nums,0,k);
        reversearr(nums,k,nums.size());
    }
};