class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
       int i=1;
        for(int j=1;j<arr.size();j++){
            if(arr[j]!=arr[j-1]){
                arr[i]=arr[j];
                i++;
            }
        }
        return i;    
    }
};