// we do not need the row flag matrix
class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;

        string tmp(n, '.');
        vector<string> combination(n, tmp);

        vector<int> column(n, 0);
        vector<int> slash(2 * n - 1, 0);
        vector<int> backslash(2 * n - 1, 0);

        dfs(column, slash, backslash, combination, count, 0, n);

        return count;
    }
private:
    void
    dfs(vector<int>& column, vector<int>& slash,vector<int>& backslash,
         vector<string>& combination, int &count, int i, int n){
        if(i == n){
            ++count;
            return;
        }
        for(int j = 0;j < n;++j){
            if((column[j] || slash[i + j] || backslash[n - 1 - i + j]) == 0){
                column[j] = 1;
                slash[i + j] = 1;
                backslash[n - 1 - i + j] = 1;
                combination[i][j] = 'Q';
                dfs(column, slash, backslash, combination, count, i + 1, n);
                combination[i][j] = '.';
                column[j] = 0;
                slash[i + j] = 0;
                backslash[n - 1 - i + j] = 0;
            }
        }
    }
};
