class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int nr = grid.size(), nc = grid[0].size();
        vector<vector<int>> mem(nr, vector<int>(nc, 0));
        mem[0][0] = grid[0][0];

        for(int i = 1;i < nr;++i){
            mem[i][0] = mem[i - 1][0] + grid[i][0];
        }
        for(int i = 1;i < nc;++i){
            mem[0][i] = mem[0][i - 1] + grid[0][i];
        }

        for(int i = 1;i < nr;++i)
            for(int j = 1;j < nc;++j)
                mem[i][j] = grid[i][j] + min(mem[i - 1][j], mem[i][j - 1]);

        return mem[nr - 1][nc - 1];
    }
};
