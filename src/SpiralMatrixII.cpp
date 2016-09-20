class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // we can use vector<vector<int>> result(n, vector<int>(n));
        vector<int> tmp(n, 0);
        vector<vector<int>> result(n, tmp);

        vector<int> pos{0, -1};
        vector<vector<int>> direction{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> count{n, n - 1};

        int step = 0;
        int num = 1;

        while(count[0] >= 0 && count[1] >= 0){
            for(int i = 0;i < count[step % 2];++i){
                pos[0] += direction[step % 4][0];
                pos[1] += direction[step % 4][1];
                result[pos[0]][pos[1]] = num;
                num++;
            }
            count[step % 2]--;
            step++;
        }
        return result;
    }
};
