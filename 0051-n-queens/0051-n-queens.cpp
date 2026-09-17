class Solution {
public:
    vector<vector<string>>ans;
    bool issafe(vector<string>&board,int row,int col,int n){
        for(int i=0;i<row;i++){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;j++,i--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void nquee(vector<string>&board,int row,int n){
        if(row==n){
           ans.push_back(board);
        }
        for(int i=0;i<n;i++){
            if(issafe(board,row,i,n)){
                board[row][i]='Q';
                nquee(board,row+1,n);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        nquee(board,0,n);
        return ans;
    }
};