class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {

            int row[9] = {0};
            int col[9] = {0};

            for(int j = 0; j < 9; j++) {

                if(board[i][j] != '.') {
                    int numrow = board[i][j] - '0';
                    row[numrow - 1]++;

                    if(row[numrow - 1] > 1)
                        return false;
                }

                if(board[j][i] != '.') {
                    int numcol = board[j][i] - '0';
                    col[numcol - 1]++;

                    if(col[numcol - 1] > 1)
                        return false;
                }
            }
        }

        for(int r = 0; r < 9; r += 3) {
            for(int c = 0; c < 9; c += 3) {

                int box[9] = {0};

                for(int i = r; i < r + 3; i++) {
                    for(int j = c; j < c + 3; j++) {

                        if(board[i][j] != '.') {
                            int num = board[i][j] - '0';
                            box[num - 1]++;

                            if(box[num - 1] > 1)
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};