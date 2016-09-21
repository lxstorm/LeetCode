class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, 1));
        for(int i = 1;i < m;++i){
            for(int j = 1;j < n;++j)
                mem[i][j] = mem[i][j - 1] + mem[i - 1][j];
        }

        return mem[m - 1][n - 1];
    }
};
// top-down Solution
/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mem(m, vector<int>(n, -1));
        mem[0][0] = 1;
        return pathRecur(mem, m, n, m - 1, n - 1);
    }
private:
    int pathRecur(vector<vector<int>> &mem, int m, int n, int i, int j){
        int res;
        if(i < 0 || j < 0)
            return 0;
        if(mem[i][j] != -1)
            return mem[i][j];
        else res =  pathRecur(mem, m, n, i - 1, j) + pathRecur(mem, m, n, i , j - 1);
        mem[i][j] = res;
        return res;
    }
};
*/
