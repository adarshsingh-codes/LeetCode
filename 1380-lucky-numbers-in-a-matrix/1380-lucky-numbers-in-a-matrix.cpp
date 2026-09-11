class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> mi;
        vector<int> ma;
        int mini=INT_MAX;
        for(int i=0;i<r;i++){
            mini=INT_MAX;
            for(int j=0;j<c;j++){
                if(mini>matrix[i][j]){
                    mini=matrix[i][j];    
                }
            }
            mi.push_back(mini);
        }
        int maxi=INT_MIN;
        for(int j=0;j<c;j++){
            maxi=INT_MIN;
            for(int i=0;i<r;i++){
                if(maxi<matrix[i][j]){
                    maxi=matrix[i][j];
                }
            }   
            ma.push_back(maxi);
        }
        vector<int>ans;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==mi[i]&&matrix[i][j]==ma[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};