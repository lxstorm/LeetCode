class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nr = matrix.size();
        if(nr == 0)
            return vector<int>();
        int nc = matrix[0].size();

        vector<int> result;
        vector<vector<int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> steps{nc, nr - 1};

        int count = 0;
        vector<int> position{0, -1};
        vector<int> idir;

        while(steps[count % 2]){
            cur_dir = directions[count % 4];
            for(int i = 0;i < steps[count % 2];++i){
                position[0] += cur_dir[0];
                position[1] += cur_dir[1];
                result.push_back(matrix[position[0]][position[1]]);
            }
            steps[count % 2]--;
            count++;
        }
        return result;

    }
};
