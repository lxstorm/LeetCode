class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int col_use[9][9], row_use[9][9], block_use[9][9];
        char tmp;
        int num;
        for(int i = 0;i < 9;++i)
            for(int j = 0;j < 9;++j){
                col_use[i][j] = 0;
                row_use[i][j] = 0;
                block_use[i][j] = 0;
            }
        for(int i = 0;i < 9;++i)
            for(int j = 0;j < 9;++j){
                tmp = board[i][j];
                if(tmp > '9' && tmp < '1' && tmp != '.')
                    return false;
                else if(tmp != '.'){
                    num = board[i][j] - '1';
                    if(row_use[i][num] || col_use[j][num]
                        || block_use[(i / 3) * 3 + j / 3][num])
                        return false;
                    row_use[i][num] = 1;
                    col_use[j][num] = 1;
                    block_use[(i / 3) * 3 + j / 3][num] = 1;
                }
            }
        return true;
    }
};
