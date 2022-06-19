class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col){
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    void solve(vector<string>&board, int row,int& ans){
        if(row == board.size()){
            ans++;
            return;
        }
        for(int i=0;i<board.size();++i){
            if(isSafe(board,row,i)){
                board[row][i] = 'Q';
                solve(board,row+1,ans);
                board[row][i] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int ans = 0;
        vector<string>board(n,string(n,'.'));
        solve(board,0,ans);
        return ans;
    }
};