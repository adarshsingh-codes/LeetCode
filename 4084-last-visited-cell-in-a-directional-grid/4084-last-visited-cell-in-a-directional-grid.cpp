class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int r=0,c=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        while(1){
            vis[r][c]=1;
            int prevr=r;
            int prevc=c;
            if(grid[r][c]=='R'){
               c++; 
            }else if(grid[r][c]=='L'){
                c--;
            }else if(grid[r][c]=='D'){
                r++;
            }else{
                r--;
            }
            if(c<0||c>=n||r<0||r>=m){
                return {prevr,prevc};
            }
            if(vis[r][c]==1){
                return {prevr,prevc};
            }
        }
        return {r,c};
    }
};