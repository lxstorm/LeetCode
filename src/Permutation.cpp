class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> combination;
        vector<int> mem(nums.size(), 0);
        dfs(nums, res, combination, mem, 0);

        return res;
    }
private:
    void dfs(vector<int> &nums, vector<vector<int>> &res,
            vector<int> &combination, vector<int> &mem, int step)
    {
        if(step == nums.size()){
            res.push_back(combination);
            return;
        }
        else{
            for(int i = 0;i < nums.size(); ++i){
                if(mem[i] == 0){
                    mem[i] = 1;
                    combination.push_back(nums[i]);
                    dfs(nums, res, combination, mem, step + 1);
                    combination.pop_back();
                    mem[i] = 0;
                }
            }
            return;
        }
    }
};
