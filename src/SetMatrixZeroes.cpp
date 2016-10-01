class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int> row(r, 0);
        vector<int> column(c, 0);

        for(int i = 0;i < r;++i)
            for(int j = 0;j < c;++j){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    column[j] = 1;
                }
            }
        for(int i = 0;i < r;++i)
            for(int j = 0;j < c;++j){
                if(row[i] == 1 || column[j] == 1){
                    matrix[i][j] = 0;
                }
            }
    }
};
/* another O(1) solution
class Solution{
public:
    void setZeroes(vector<vector<int>>& matrix){
        int r = matrix.size();
        int c = matrix[0].size();
        int col0 = 1;

        for(int i = 0;i < r;++i){
            if(matrix[i][0] == 0)
                col0 = 0;
            for(int j = 1;j < c;++j){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // if we do not from r - 1 to 0, when row[0][0] == 0, the row0 will be
        // all 0, that will affect the following number;
        // and the statement (col == 0) should be placed after the j-for to avoid
        // after we set matrix[i][0] = 0, then when we check matrix(i, 0) matrix(j, 0)
        // the whole i-row will be set to 0;
        for(int i = r - 1;i >= 0;--i){
            for(int j = c - 1;j >= 1;--j){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
            if(col0 == 0)   matrix[i][0] = 0;
        }
    }
};
*/
