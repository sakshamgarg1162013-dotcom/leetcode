class Solution {
private:
    bool issafe(vector<vector<char>>& board, int row, int col, char num) {

        for(int i = 0; i < 9; i++) {
            if(board[row][i] == num) {
                return false;
            }
            if(board[i][col] == num) {
                return false;
            }
        }

        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for(int i = startRow; i < startRow + 3; i++) {
            for(int j = startCol; j < startCol + 3; j++) {
                if(board[i][j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    bool solve(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]=='.'){
                    for(char n ='1';n<='9';n++){

                        if(issafe(board,i,j,n)){
                            board[i][j] = n;

                            if(solve(board)){
                                return true;
                            }
                            board[i][j] = '.';
                        }

                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};