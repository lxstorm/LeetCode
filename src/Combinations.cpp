class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;

        helper(0, 1, n, k,  result, combination);

        return result;
    }
private:
    // we can also change k to 0 to mark the numbers to be added to the combination
    void helper(int step, int start, int n, int k, vector<vector<int>> &result, vector<int> &combination){
        if(step == k){
            result.push_back(combination);
            return;
        }
        else{
            for(int i = start;i <= n - k + step + 1 ;++i){
                combination.push_back(i);
                helper(step + 1, i + 1, n, k, result, combination);
                combination.pop_back();
            }
        }
    }
};
