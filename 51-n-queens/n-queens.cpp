class Solution {
private:
    bool issafe(vector <string> &board,int row,int col,int n){
        int x=row;
        int y=col;
        while(x>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
        }
        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x>=0 && y<n){
            if(board[x][y]=='Q'){
                return false;
            }
            x--;
            y++;
        }
        return true;
    }
    void solve(vector <vector<string>> &ans,vector <string> &board,int row,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int col=0;col<n;col++){
            if(issafe(board,row,col,n)){
                board[row][col] = 'Q';
                solve(ans,board,row+1,n);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(ans,board,0,n);
        return ans;
    }
};