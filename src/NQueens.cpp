class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string tmp(n, '.');
        vector<string> combination(n, tmp);

        vector<int> row(n, 0);
        vector<int> column(n, 0);
        vector<int> slash(2 * n - 1, 0);
        vector<int> backslash(2 * n - 1, 0);

        dfs(row, column, slash, backslash, combination, result, 0, n);

        return result;
    }
private:
    void
    dfs(vector<int>& row, vector<int>& column, vector<int>& slash,
    vector<int>& backslash, vector<string>& combination,
    vector<vector<string>>& result, int i, int n){
        if(i == n){
            result.push_back(combination);
            return;
        }
        for(int j = 0;j < n;++j){
            // if statement use bracket
            if((row[i] || column[j] || slash[i + j] || backslash[n - 1 - i + j]) == 0){
                row[i] = 1;
                column[j] = 1;
                slash[i + j] = 1;
                backslash[n - 1 - i + j] = 1;
                combination[i][j] = 'Q';
                dfs(row, column, slash, backslash, combination, result, i + 1, n);
                combination[i][j] = '.';
                row[i] = 0;
                column[j] = 0;
                slash[i + j] = 0;
                backslash[n - 1 - i + j] = 0;
            }
        }
    }
};
