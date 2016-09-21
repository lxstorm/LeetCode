class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int nr = obstacleGrid.size();
        int nc = obstacleGrid[0].size();

        vector<vector<int>> mem(nr + 1, vector<int>(nc + 1, 0));
        mem[0][1] = 1;
        for(int i = 1;i <= nr ;++i){
            for(int j = 1;j <= nc;++j){
                if(obstacleGrid[i - 1][j - 1] == 1)
                    mem[i][j] = 0;
                else
                    mem[i][j] = mem[i - 1][j] + mem[i][j - 1];
            }
        }
        return mem[nr][nc];
    }
};
