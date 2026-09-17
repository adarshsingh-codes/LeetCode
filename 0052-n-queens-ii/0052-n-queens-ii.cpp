class Solution {
public:
    int count=0;
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
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void nquee(vector<string>&board,int row,int n){
        if(row==n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(board,row,i,n)){
                board[row][i]='Q';
                nquee(board,row+1,n);
                board[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        nquee(board,0,n);
        return count;
    }
};