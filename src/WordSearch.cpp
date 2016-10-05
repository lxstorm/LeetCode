class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                if(dfs(i, j, 0, m, n, word, board))
                    return true;
            }
        return false;
    }
private:
    bool dfs(int r, int c, int step, int m, int n, string &word, vector<vector<char>>& board){
        if(step == word.size())
            return true;
        else if(r >= m || r < 0 || c >= n || c < 0 || board[r][c] == '*' || board[r][c] != word[step])
            return false;
        // board[r][c] == word[step]
        else {
            board[r][c] = '*';
            if(dfs(r + 1, c, step + 1, m, n, word, board) ||
                dfs(r - 1, c, step + 1, m, n, word, board) ||
                dfs(r, c + 1, step + 1, m, n, word, board) ||
                dfs(r, c - 1, step + 1, m, n, word, board)
            )
                return true;
            board[r][c] = word[step];
            return false;
        }
    }
};
