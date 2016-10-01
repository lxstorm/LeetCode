/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ri = 0;
        int rj = matrix.size() - 1;

        while(ri < rj){
            int mid = ri + (rj - ri + 1) / 2;
            if(matrix[mid][0] > target)
                rj = mid - 1;
            else if(matrix[mid][0] < target)
                ri = mid;
            else
                return true;
        }

        int row = rj;
        int ci = 0;
        int cj = matrix[0].size() - 1;
        while(ci < cj){
            int mid = ci + (cj - ci) / 2;
            if(matrix[row][mid] > target)
                cj = mid - 1;
            else if(matrix[row][mid] < target)
                ci = mid + 1;
            else
                return true;
        }
        if(matrix[row][ci] == target)
            return true;
        else
            return false;
    }
};
*/
/* another solution treate the matrix as a sorted list*/
class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = m * n - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(matrix[mid / n][mid % n] > target)
                r = mid - 1;
            else if(matrix[mid / n][mid % n] < target)
                l = mid + 1;
            else
                return true;
        }
        return false;
    }
};
