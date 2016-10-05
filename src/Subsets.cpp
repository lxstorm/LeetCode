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
/*  can also use bit manipulation, if 1, 2, 3
    so 0 0 0 means 1 not 2 not 3 not in
       0 0 1 means 1 not 2 not 3 is in
       there are 2 ^ 3 = 8 subsets assume they are in subsets_list
       for i in 1...8:
        for j in 0...2: (3 nums)
            if(i >> j & 1):  // jth bit
                subsets_list[i].push_back(nums[j])
*/
