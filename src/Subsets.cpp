class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        dfs(0, nums, subset, result);

        return result;
    }
private:
    void dfs(int begin, vector<int> &nums, vector<int> &subset,
            vector<vector<int>> &result){
        result.push_back(subset);
        for(int i = begin;i < nums.size();++i){
            subset.push_back(nums[i]);
            dfs(i + 1, nums, subset, result);
            subset.pop_back();
        }
    }
};
/* another iterative way
class Solution{
public:
    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> result(1, vector<int>());

        for(int i = 0; i < nums.size();++i){
            int len = result.size();
// can not put the result.size() in the for loop because its size is always growing
            for(int j = 0; j < len;++j){
                result.push_back(result[j]);
                result.back().push_back(nums[i]);

            }
        }
        return result;
    }
};
*/
